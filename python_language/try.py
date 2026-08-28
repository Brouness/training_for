import time
import signal
import sys

def handle_ctrl_z(signum, frame):
    print("\nCtrl+Z was pressed! Performing cleanup before exiting...")
    sys.exit(0)

try:
    signal.signal(signal.SIGTSTP, handle_ctrl_z)
    time.sleep(5)
    print("toundfksng")
except KeyboardInterrupt:
    print("you are gay")
