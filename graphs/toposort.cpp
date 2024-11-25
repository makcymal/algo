vi toposort(vvi &graph) {
  vi order; order.reserve(graph.size());
  vector<bool> seen(graph.size(), false);
  for (int v = 0; v < graph.size(); ++v) if (!seen[v]) dfs(graph, seen, order, v);
  reverse(all(order));
  return order;
}
void dfs(vvi &graph, vector<bool> &seen, vi &order, int v) {
  seen[v] = true;
  for (int to: graph[v]) if (!seen[to]) dfs(graph, seen, order, to);
  order.push_back(v);
}
