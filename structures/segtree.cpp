struct Segtree {
  typedef int T;
  static const T unit = INT32_MIN;
  T f(T a, T b) { return max(a, b); };
  vector<T> tree;
  int size;

  Segtree(int sz, T def = unit) : size(__bit_ceil(sz)), tree(2 * sz, def) {}
  Segtree(vector<T> &data) {
    size = __bit_ceil(data.size());
    tree.resize(2 * size);
    copy(data.begin(), data.end(), tree.begin() + size);
    for (int i = size - 1; i > 0; --i) tree[i] = f(tree[2 * i], tree[2 * i + 1]);
  }
  T get(int i) { return tree[size + i]; }
  T qry(int lb, int rb) {
    T lf = unit, rf = unit;
    for (lb += size, rb += size; lb < rb; lb /= 2, rb /= 2) {
      if (lb % 2) lf = f(lf, tree[lb++]);
      if (rb % 2) rf = f(tree[--rb], rf);
    }
    return f(lf, rf);
  }
  void upd(int i, T val) {
    tree[i + size] = f(tree[i + size], val);
    for (i += size; i /= 2;) tree[i] = f(tree[2 * i], tree[2 * i + 1]);
  }
  void set(int i, T val) {
    for (tree[i += size] = val; i /= 2;) tree[i] = f(tree[2 * i], tree[2 * i + 1]);
  }
};
