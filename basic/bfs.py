from collections import deque
def bfs(g, s):
  dist, prev = [-1] * len(g), [-1] * len(g)
  dist[s] = 0; q = deque([s])
  while q:
    v = q.popleft()
    for to in g[v]:
      if dist[to] == -1:
        dist[to] = dist[v] + 1; prev[to] = v; q.append(to)
  return dist, prev