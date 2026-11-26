def dfs_iterative(g, s):
  seen = [False] * len(g); seen[s] = True
  order, stack = [s], [iter(g[s])]
  while stack:
    to = next(stack[-1], None)
    if to is None: stack.pop()
    elif not seen[to]:
      seen[to] = True
      order.append(to)
      stack.append(iter(g[to]))
  return order