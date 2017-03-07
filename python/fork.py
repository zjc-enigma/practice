import os
import sys
import time

test_file = "/tmp/test.fork"

try:
    if os.fork() > 0:
        pass

    else:
        with open(test_file, 'w') as f:
            print('enter child process', os.getpid())
            while True:
                print(os.getpid())
                time.sleep(3)


except OSError as e:
    raise RuntimeError('fork failed')

print('--end--', os.getpid())
