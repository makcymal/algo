def kruskal(n, edges):
  dsu, total, chosen = DSU(n), 0, []
  for u, v, w in sorted(edges, key=lambda e: e[2]):
    if dsu.join(u, v): total += w; chosen.append((u, v, w))
  return (total, chosen) if len(chosen) == n - 1 else None