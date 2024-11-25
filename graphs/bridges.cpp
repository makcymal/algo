vvi graph; vector<bool> seen; vi tin, low; int timer = 0;

void find_bridges() {
  seen.assign(graph.size(), false);
  tin.assign(graph.size(), -1), low.assign(graph.size(), -1);
  for (int v = 0; v < graph.size(); ++v)
    if (!seen[v]) dfs(v);
}
void dfs(int v, int p = -1) {
  seen[v] = true;
  tin[v] = low[v] = timer++;
  for (int to: graph[v]) {
    if (to == p) continue;
    if (seen[to]) {
      low[v] = min(low[v], tin[to]);
    } else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if (low[to] > tin[v]) ITS_BRIDGE(v, to);
    }
  }
}
