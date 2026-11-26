import sys
input = sys.stdin.readline # 10x faster than usual input(), but leaves \n, call .strip()
data = sys.stdin.read().split() # read all the input at once
sys.stdout.write("\n".join(map(str, results))+"\n") # collect results, print all at once