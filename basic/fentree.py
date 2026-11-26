class Fentree:
  def __init__(self, n_or_values):
    if isinstance(n_or_values, int):
      self.n = n_or_values; self.tree = [0] * (self.n + 1)
    else:
      values = list(n_or_values)
      self.n = len(values); self.tree = [0] * (self.n + 1)
      for i, v in enumerate(values, start=1):
        self.tree[i] += v
        parent = i + (i & -i)
        if parent <= self.n: self.tree[parent] += self.tree[i]
  def prefix(self, i):        # 0B: sum[0, i]
    s = 0
    while i > 0: s += self.tree[i]; i -= i & -i
    return s
  def update(self, i, val):   # 0B
    i += 1
    while i <= self.n: self.tree[i] += val; i += i & -i
  def query(self, lb, rb):    # 0B, EI
    return self.prefix(rb + 1) - self.prefix(lb)