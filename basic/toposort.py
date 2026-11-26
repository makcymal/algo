from collections import deque
def topological_sort(g):
  deg = [0] * len(g)
  for row in g:
      for to in row: deg[to] += 1
  q, order = deque(v for v in range(len(g)) if deg[v] == 0), []
  while q:
    v = q.popleft(); order.append(v)
    for to in g[v]:
      deg[to] -= 1
      if deg[to] == 0: q.append(to)
  return order if len(order) == len(g) else None