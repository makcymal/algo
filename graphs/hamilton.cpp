// mask - set of nodes to walk through without end
int count(int start, int end, int mask, vvi &dp, vvi &g) {
  if (mask == (1 << start)) return g[start][end] > 0 ? 1 : 0;
  if (dp[mask][end] != -1) return dp[mask][end];
  int res = 0;
  for (int bit = 0; bit < g.size(); ++bit) {
    if (bit == start or bit == end) continue;
    if ((mask & (1 << bit)) != 0 and g[bit][end] > 0)
    res += count(start, bit, mask - (1 << bit), dp, g);
  } return dp[mask][end] = res;
}
// returns mask of set of nodes where traversal may end
int check(int mask, vi &dp, vi &g) {
  if ((mask & (mask - 1)) == 0) return mask;
  if (dp[mask] != -1) return dp[mask];
  int res = 0;
  for (int bit = 0; bit < g.size(); ++bit) {
    if ((mask & (1 << bit)) != 0 and (check(mask & ~(1 << bit), dp, g) & g[bit]) != 0)
      res += 1 << bit;
  } return dp[mask] = res;
}
