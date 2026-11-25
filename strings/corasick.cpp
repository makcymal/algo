struct AhoCorasick {
  static const int K = 26;
  vector<array<int, K>> go; vi suff, exit, cnt, order;
  AhoCorasick() { new_node(); }
  int new_node() {
    go.emplace_back(); go.back().fill(-1);
    suff.push_back(0); exit.push_back(0); cnt.push_back(0);
    return go.size() - 1;
  }
  int insert(string &s) {
    int v = 0;
    for (char ch : s) {
      if (go[v][ch-'a'] == -1) { int u = new_node(); go[v][ch-'a'] = u; }
      v = go[v][ch-'a'];
    }
    cnt[v]++; return v;
  }
  int search(string &s) {   // works only before build()
    int v = 0;
    for (char ch : s) { v = go[v][ch-'a']; if (v == -1) return -1; }
    return v;
  }
  void build() {  // call once after all insert()'s
    order.assign(1, 0);
    for (int i = 0; i < order.size(); i++) {
      int v = order[i];
      if (v > 0) exit[v] = cnt[suff[v]] ? suff[v] : exit[suff[v]];
      for (int c = 0; c < K; c++) {
        int u = go[v][c]; int f = v > 0 ? go[suff[v]][c] : 0;
        if (u == -1) go[v][c] = f;
        else { suff[u] = f; order.push_back(u); }
      } } }
  int get_suff(int v) { return suff[v]; }
  int get_exit(int v) { return exit[v]; }
  int get_transition(int v, char ch) { return go[v][ch-'a']; }
};