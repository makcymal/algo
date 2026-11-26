def graph_components(g):
  comp, count = [-1] * len(g), 0
  for s in range(len(g)):
    if comp[s] != -1: continue
    comp[s], stack = count, [s]
    while stack:
      v = stack.pop()
      for to in g[v]:
        if comp[to] == -1: comp[to] = count; stack.append(to)
    count += 1
  return comp, count