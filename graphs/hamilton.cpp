int shortest_hamilton(int mask, int end, vvi &dp, vector<hashmap<int, int>> &graph) {
  if ((mask & (mask - 1)) == 0) return 0;
  if (dp[mask][end] != -1) return dp[mask][end];
  int len = INT32_MAX;
  for (int bit = 0; bit < 32; ++bit) {
    if ((mask & (1 << bit)) == 0) continue;
    if (graph[bit].count(end) == 0) continue;
    len = min(len, shortest_hamilton(mask & ~(1 << end), bit, dp, graph) +
                   graph[bit].find(end)->second);
  }
  return dp[mask][end] = len;
}
int count_hamiltons(int mask, int end, vvi &dp, vector<hashset<int>> &graph) {
  if ((mask & (mask - 1)) == 0) return 1;
  if (dp[mask][end] != -1) return dp[mask][end];
  int cnt = 0;
  for (int bit = 0; bit < 32; ++bit) {
    if ((mask & (1 << bit)) == 0) continue;
    if (graph[bit].count(end) == 0) continue;
    cnt += count_hamiltons(mask & ~(1 << end), bit, dp, graph);
  }
  return dp[mask][end] = cnt;
}
int check_hamilton(int mask, vi &dp, vi &graph) {
  if ((mask & (mask - 1)) == 0) return mask;
  if (dp[mask] != -1) return dp[mask];
  int ans = 0;
  for (int bit = 0; bit < 32; ++bit) {
    if ((mask & (1 << bit)) == 0) continue;
    if ((check_hamilton(mask & ~(1 << bit), dp, graph) & graph[bit]) != 0)
      ans += 1 << bit;
  }
  return dp[mask] = ans;
}
