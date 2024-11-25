void dfs(int v, int p = -1) {
  seen[v] = true;
  tin[v] = low[v] = timer++;
  int children = 0;
  for (int to: graph[v]) {
    if (to == p) continue;
    if (seen[to]) {
      low[v] = min(low[v], tin[to]);
    } else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v] and p != -1) ITS_CUTPOINT(v);
      children++;
    }
  }
  if (p == -1 and children > 1) ITS_CUTPOINT(v);
}
