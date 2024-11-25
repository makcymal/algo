pair<vi, bool> spf(vector<vector<pii>> &graph, int src) {
  int n = graph.size();
  vi dist(n, INT32_MAX), cnt(n, 0); dist[src] = 0;
  vector<bool> inqueue(n, false); inqueue[src] = true;
  queue<int> q; q.push(src); 

  while (!q.empty()) {
    int v = q.front(), d = dist[q.front()];
    q.pop();
    inqueue[v] = false;
    for (auto [to, len] : graph[v]) {
      if (d + len >= dist[to]) continue;
      dist[to] = d + len;
      if (inqueue[to]) continue;
      q.push(to);
      inqueue[to] = true;
      cnt[to]++;
      if (cnt[to] > n) return {dist, false};  // negative cycle
    }
  }
  return {dist, true};
}
