struct LazySegtree {
  typedef int T;
  vector<T> tree, lazy;
  int size;

  LazySegtree(vector<T> &data) : size(__bit_ceil(data.size())) {
    tree.resize(2 * size, INT32_MAX);
    lazy.resize(2 * size);
    copy(data.begin(), data.end(), tree.begin() + size);
    for (int i = size - 1; i > 0; --i) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }

  T query(int ql, int qr, int node = 1, int lb = 0, int rb = -1) {
    if (rb == -1) rb = size;
    if (qr <= lb or rb <= ql) return INT32_MAX;
    if (ql <= lb && rb <= qr) return tree[node];
    push(node, lb, rb);
    int md = lb + (rb - lb + 1) / 2;
    return min(query(ql, qr, 2 * node, lb, md), query(ql, qr, 2 * node + 1, md, rb));
  }

  void update(int ql, int qr, T x, int node = 1, int lb = 0, int rb = -1) {
    if (rb == -1) rb = size;
    if (qr <= lb or rb <= ql) return;
    if (ql <= lb && rb <= qr) {
      lazy[node] += x;
      tree[node] += x;
    } else {
      push(node, lb, rb);
      int md = lb + (rb - lb + 1) / 2;
      update(ql, qr, x, 2 * node, lb, md);
      update(ql, qr, x, 2 * node + 1, md, rb);
      tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
  }

  void push(int node, int lb, int rb) {
    if (lazy[node]) {
      int md = lb + (rb - lb + 1) / 2;
      update(lb, rb, lazy[node], 2 * node, lb, md);
      update(lb, rb, lazy[node], 2 * node + 1, md, rb);
      lazy[node] = 0;
    }
  }
};
