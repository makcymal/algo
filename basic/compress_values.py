def compress(a):
  values = sorted(set(a))
  rank = {x: i for i, x in enumerate(values)}
  return [rank[x] for x in a], values