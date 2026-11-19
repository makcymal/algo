vi dijkstra(vector<vector<pii>> &g, int src) {
  vector<pair<ll, int>> hp;
  dist[src] = 0;
  hp.push_back({src, 0});
  while (!hp.empty()) {
    auto [d, v] = HP_POP(hp);
    if (d > dist[v]) continue;
    for (auto [to, len]: g[v]) {
      if (d + len < dist[to]) {
        dist[to] = d + len;
        prev[to] = v;
        HP_PUSH(hp, make_pair(dist[to], to));
      }
    }
  }
  return dist;
}
