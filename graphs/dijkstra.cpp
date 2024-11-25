vi dijkstra(vector<vector<pii>> &graph, int src) {
  int n = graph.size();
  vi dist(n, INT32_MAX);
  dist[src] = 0;
  priority_queue<pii, vpii, greater<>> pq;
  pq.emplace(0, src);
  while (!pq.empty()) {
    while (!pq.empty() and dist[pq.top().S] <= pq.top().F) pq.pop();
    if (pq.empty()) continue;
    auto [d, v] = pq.top();
    pq.pop();
    dist[v] = d;
    for (auto [to, len] : graph[v]) pq.emplace(d + len, to);
  }
  return dist;
}
