import sys
from daemon import runner
sys.path.append("/root/.local/lib64/python3.5/site-packages")

class Test:

    def __init__(self):
        self.word = "hehe"


    def run(self):
        print("hello" + self.word)


t = Test()
r = runner.Daemonrunner(t)
r.do_action()
