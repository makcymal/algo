struct LazySegtree {
  typedef int T;
  static const T unit = 0;
  vector<T> tree, lazy;
  int size;

  LazySegtree(int sz)
  : size(__bit_ceil(sz)), tree(2 * __bit_ceil(sz)), lazy(2 * __bit_ceil(sz)) {}
  T qry(int ql, int qr, int node = 1, int lb = 0, int rb = -1) {
    if (rb == -1) rb = size;
    if (qr <= lb or rb <= ql) return 0;
    if (ql <= lb && rb <= qr) return tree[node];
    push(node, lb, rb);
    int md = lb + (rb - lb + 1) / 2;
    return max(qry(ql, qr, 2 * node, lb, md), qry(ql, qr, 2 * node + 1, md, rb));
  }
  void upd(int ql, int qr, T x, int node = 1, int lb = 0, int rb = -1) {
    if (rb == -1) rb = size;
    if (qr <= lb or rb <= ql) return;
    if (ql <= lb && rb <= qr) {
      lazy[node] = max(lazy[node], x);
      tree[node] = max(tree[node], x);
    } else {
      push(node, lb, rb);
      int md = lb + (rb - lb + 1) / 2;
      upd(ql, qr, x, 2 * node, lb, md);
      upd(ql, qr, x, 2 * node + 1, md, rb);
      tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
  }
  void push(int node, int lb, int rb) {
    if (lazy[node]) {
      int md = lb + (rb - lb + 1) / 2;
      upd(lb, rb, lazy[node], 2 * node, lb, md);
      upd(lb, rb, lazy[node], 2 * node + 1, md, rb);
      lazy[node] = 0;
    }
  }
};
