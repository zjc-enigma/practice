import os
import sys
import atexit
import signal




def daemonize(pidfile, *,
              stdin='/dev/null',
              stdout='/dev/null',
              stderr='/dev/null'):

    if os.path.exists(pidfile):
        raise RuntimeError('daemon already running')

    # first fork
    try:
        if os.fork() > 0 : # parent exit
            raise SystemExit(0)

    except OSError as e:
        raise RuntimeError('first fork failed')


    os.chdir('/')
    os.umask(0) # ?
    os.setsid() #?

    # second fork
    try:
        if os.fork() > 0: # parent exit
            raise SystemExit(0)

    except OSError as e:
        raise RuntimeError('second fork failed')


    sys.stdout.flush()
    sys.stderr.flush()

    with open(stdin, 'rb', 0) as f: # 0 ?
        os.dup2(f.fileno(), sys.stdin.fileno())

    with open(stdout, 'ab', 0)  as f:
        os.dup2(f.fileno(), sys.stdout.fileno())

    with open(stderr, 'ab', 0) as f:
        os.dup2(f.fileno(), sys.stderr.fileno())

    with open(pidfile, 'w') as f:
        print(os.getpid(), file=f) # !print file args

    # remove pid file on exit signal
    atexit.register(lambda: os.remove(pidfile))


    def sigterm_handler(signo, frame):
        raise SystemExit(1)

    signal.signal(signal.SIGTERM, sigterm_handler)


def main():
    import time
    sys.stdout.write('Daemon started with pid {}\n'.format(os.getpid()))
    while True:
        sys.stdout.write('Daemon alive! {}\n'.format(time.ctime()))
        time.sleep(10)



if __name__ == '__main__':
    PID_FILE = '/tmp/daemonize.pid'
    try:
        daemonize(PID_FILE,
                  stdout='/tmp/daemon.log',
                  stderr='/tmp/daemon.log')
    except RuntimeError as e:
        print(e, file=sys.stderr)
        raise SystemExit(1)

    main()
    
