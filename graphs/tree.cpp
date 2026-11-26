struct RootedTree {
  int n, LOG; vi tin, tout, parent, depth, preorder, leafs;
  vvi up; // up[j][v] = 2^{j} ancestor (root's ancestors are the root)
  RMQ preorder_rmq; // min of (depth, parent) over preorder, add default empty ctor to RMQ!
  RootedTree(vvi &g, int src) : n(g.size()), tin(n), tout(n), parent(n, -1), depth(n, 0) {
    vi st = {src}, ptr(n, 0); int timer = 0; tin[src] = timer++;
    preorder.reserve(n); preorder.push_back(src);
    while (!st.empty()) {
      int v = st.back();
      if (ptr[v] < (int)g[v].size()) {
        int to = g[v][ptr[v]++]; if (to == parent[v]) continue;
        parent[to] = v; depth[to] = depth[v] + 1; tin[to] = timer++;
        preorder.push_back(to); st.push_back(to);
      } else {
        tout[v] = timer; st.pop_back(); if (tout[v] - tin[v] == 1) leafs.push_back(v);
      } }
    LOG = 1; while ((1 << LOG) < n) LOG++; up.assign(LOG, vi(n));
    for (int v = 0; v < n; ++v) up[0][v] = parent[v] == -1 ? v : parent[v];
    for (int j=1; j<LOG; ++j) for (int v=0; v<n; ++v) up[j][v]=up[j-1][up[j-1][v]];
    vector<pii> a(n); for (int v = 0; v < n; ++v) a[tin[v]] = {depth[v], parent[v]};
    preorder_rmq = RMQ(a);
  }
  bool is_ancestor(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }
  int lca_ups(int a, int b) {
    if (is_ancestor(a, b)) return a; if (is_ancestor(b, a)) return b;
    for (int j = LOG - 1; j >= 0; --j) if (!is_ancestor(up[j][a], b)) a = up[j][a];
    return up[0][a];
  }
  int lca_rmq(int a, int b) {
    if (a == b) return a;
    if (tin[a] > tin[b]) swap(a, b);
    return preorder_rmq.query(tin[a] + 1, tin[b] + 1).second;
  } };