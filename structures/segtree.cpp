struct Segtree {    // min! for sum INT32_MAX->0, min->+
  int size; vector<T> tree;
  Segtree(int sz, T def = INT32_MAX) : size(bit_ceil(sz)), tree(2 * size, def) {}
  Segtree(vector<T> &data) : size(bit_ceil(data.size())) {
    tree.assign(2 * size, INT32_MAX);
    copy(data.begin(), data.end(), tree.begin() + size);
    for (int i = size - 1; i > 0; --i) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }
  T get(int i) { return tree[size + i]; } // 0B
  T query(int lb, int rb) { // 0B,EE
    T lf = INT32_MAX, rf = INT32_MAX;
    for (lb += size, rb += size; lb < rb; lb /= 2, rb /= 2) {
      if (lb % 2) lf = min(lf, tree[lb++]); if (rb % 2) rf = min(tree[--rb], rf);
    } return min(lf, rf);
  }
  void update(int i, T val) { // 0B
    tree[i + size] = min(tree[i + size], val);
    for (i += size; i /= 2;) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  } };