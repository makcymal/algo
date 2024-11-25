pair<vi, vi> scc(vvi &graph) {
  int n = graph.size();
  vvi trans(n);
  vi order; order.reserve(n);
  vector<bool> seen(n, false);
  for (int v = 0; v < n; ++v) {
    for (int to: graph[v]) trans[to].push_back(v);
    if (!seen[v]) dfs(graph, seen, order, v);
  }
  reverse(all(order));
  vi component(n, -1);
  int n_components = 0;
  for (int v: order) 
    if (component[v] == -1) tdfs(trans, component, n_components, v), n_components++;
  return {component, order}; 
}
void dfs(vvi &graph, vector<bool> &seen, vi &order, int v) {
  seen[v] = true;
  for (int to: graph[v]) if (!seen[to]) dfs(graph, seen, order, to);
  order.push_back(v);
}
void tdfs(vvi &trans, vi &component, int n_components, int v) {
  component[v] = n_components;
  for (int to: trans[v])
    if (component[to] == -1) tdfs(trans, component, n_components, to);
}
