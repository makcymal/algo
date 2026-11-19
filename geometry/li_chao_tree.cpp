struct LiChao {
  struct Line {
    ll k, b;
    ll operator()(ll x) const { return k * x + b; }
  };
  struct Node {
    Line ln;
    int l, r;
    Node() : ln{0, LLONG_MAX}, l(-1), r(-1) { }
  };
  vector<Node> t;
  ll L, R;
  LiChao(ll l, ll r) : t(1), L(l), R(r) { }
  int mk() { t.emplace_back(); return (int) t.size() - 1; }
  void ins(int v, ll l, ll r, Line nw) {
    while (true) {
      ll m = l + (r - l) / 2;
      bool lef = nw(l) < t[v].ln(l), mid = nw(m) < t[v].ln(m);
      if (mid) swap(t[v].ln, nw);
      if (l == r || nw.b == LLONG_MAX) return;
      if (lef != mid) {
        if (t[v].l < 0) { int c = mk(); t[c].ln = nw; t[v].l = c; return; }
        v = t[v].l; r = m;
      } else {
        if (t[v].r < 0) { int c = mk(); t[c].ln = nw; t[v].r = c; return; }
        v = t[v].r; l = m + 1;
      }
    }
  }
  void seg(int v, ll l, ll r, ll ql, ll qr, Line nw) {
    if (ql <= l && r <= qr) { ins(v, l, r, nw); return; }
    ll m = l + (r - l) / 2;
    if (ql <= m) {
      if (t[v].l < 0) { int c = mk(); t[v].l = c; }
      seg(t[v].l, l, m, ql, qr, nw);
    }
    if (qr > m) {
      if (t[v].r < 0) { int c = mk(); t[v].r = c; }
      seg(t[v].r, m + 1, r, ql, qr, nw);
    }
  }
  void add(ll k, ll b) { ins(0, L, R, Line{k, b}); }
  void add(ll k, ll b, ll lo, ll hi) {
    lo = max(lo, L); hi = min(hi, R);
    if (lo > hi) return;
    seg(0, L, R, lo, hi, Line{k, b});
  }
  ll query(ll x) {
    ll res = LLONG_MAX;
    int v = 0; ll l = L, r = R;
    while (v >= 0) {
      res = min(res, t[v].ln(x));
      if (l == r) break;
      ll m = l + (r - l) / 2;
      if (x <= m) { v = t[v].l; r = m; }
      else { v = t[v].r; l = m + 1; }
    }
    return res;
  }
};