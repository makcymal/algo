import sys, threading
sys.setrecursionlimit(10**6)
threading.stack_size(1 << 26) # 64mb

def main():
  pass  # here goes a solution

threading.Thread(target=main).start()