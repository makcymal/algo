import random
class DSU:
  def __init__(self, n):
    self.parent = list(range(n))
  def find(self, x):
    root = x
    while self.parent[root] != root: root = self.parent[root]
    while self.parent[x] != root: self.parent[x], x = root, self.parent[x]
    return root
  def join(self, a, b):
    a, b = self.find(a), self.find(b)
    if a == b: return False
    if random.randint(0, 1) == 0: self.parent[b] = a
    else: self.parent[a] = b
    return True