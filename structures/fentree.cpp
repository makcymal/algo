struct Fentree {
  typedef int T;
  vector<T> tree;
  int size;

  Fentree(int sz, T def = 0) : size(sz), tree(sz + 1) {
    for (int i = 1; i <= size; ++i) tree[i] = def * (i & -i);
  }
  Fentree(vector<T> &data) : size(data.size()), tree{0, data[0]} {
    tree.reserve(size + 1);
    vector<T> pref;
    pref.reserve(size); pref.push_back(data[0]);
    for (int i = 2; i <= data.size(); ++i) {
      pref.push_back(pref.back() + data[i - 1]);
      tree.push_back(pref.back());
      if (i != __bit_floor(i)) tree.back() -= pref[i - (i & -i) - 1];
    }
  }
  T get(int i) { return qry(i, i); }
  T qry(int rb) {
    int res = 0;
    for (rb += 1; rb > 0; rb -= (rb & -rb)) res += tree[rb];
    return res;
  }
  T qry(int lb, int rb) { return qry(rb) - qry(lb - 1); }
  void upd(int i, T val) {
    for (i += 1; i <= size; i += (i & -i)) tree[i] += val;
  }
  void set(int i, T val) { upd(i, val - get(i)); }
  void append(T val) {
    tree.push_back(val);
    int rb = tree.size() - 1;
    int lb = rb - (rb & -rb) + 1;
    if (1 <= lb and lb <= rb - 1) tree.back() += qry(lb, rb - 1);
  }
  int upper_bound(T x) {
    int i = 0;
    for (int pw = __bit_floor(tree.size()); pw >= 1; pw >>= 1) {
      if (i + pw < tree.size() and tree[i + pw] <= x) {
        i += pw;
        x -= tree[i];
      }
    }
    return i;
  }
};
