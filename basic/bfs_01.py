from collections import deque
def bfs_01(g, s):
  dist = [float("inf")] * len(g); dist[s] = 0
  q = deque([(s, 0)])
  while q:
    v, d = q.popleft()
    if d != dist[v]: continue
    for to, w in g[v]:
      nd = d + w
      if nd < dist[to]:
        dist[to] = nd
        if w == 0: q.appendleft((to, nd))
        else: q.append((to, nd))
  return dist