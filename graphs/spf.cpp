tuple<vll, vi, vi> spfa(vector<vpii> &g, int src) {
  int n = g.size(), in_neg_cycle = -1;
  vll dist(n, INT64_MAX); dist[src] = 0; vi prev(n, -1), cnt(n, 0);
  queue<int> relaxed; vb in_relaxed(n, false);
  relaxed.push(src); in_relaxed[src] = true;
  while (!relaxed.empty()) {
    int u = relaxed.front(); relaxed.pop(); in_relaxed[u] = false;
    for (auto [v, d] : g[u]) {
      if (dist[u] + d < dist[v]) {
        dist[v] = dist[u] + d; prev[v] = u;
        if (!in_relaxed[v]) { relaxed.push(v); in_relaxed[v] = true; cnt[v]++; }
        if (cnt[v] > n) { in_neg_cycle = v; break; }
      } }
    if (in_neg_cycle != -1) break;
  }
  if (in_neg_cycle == -1) return {dist, prev, {}};
  int u = in_neg_cycle; vi neg_cycle;
  for (int i = 0; i < n; ++i) u = prev[u];
  for (int curr = u;; curr = prev[curr]) {
    neg_cycle.PB(curr);
    if (curr == u and neg_cycle.size() > 1) break;
  }
  reverse(all(neg_cycle)); return {dist, prev, neg_cycle};
}