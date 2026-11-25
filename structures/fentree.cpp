struct Fentree {
  int size; vector<T> tree;
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
      if (i != bit_floor(i)) tree.back() -= pref[i - (i & -i) - 1];
    }
  }
  T query(int rb) { // 0B,EI
    T res = 0;
    for (rb += 1; rb > 0; rb -= (rb & -rb)) res += tree[rb];
    return res;
  }
  T query(int lb, int rb) { return query(rb) - query(lb - 1); } // 0B,EI
  void update(int i, T val) { // 0B,EI
    for (i += 1; i <= size; i += (i & -i)) tree[i] += val;
  }
  void append(T val) {
    tree.push_back(val); size++;
    int rb = tree.size() - 1;
    int lb = rb - (rb & -rb) + 1;
    if (1 <= lb and lb <= rb - 1) tree.back() += query(lb - 1, rb - 2);
  }
  int lower_bound(T x) {
    int i = 0;
    for (int pw = bit_floor(tree.size()); pw >= 1; pw >>= 1) {
      if (i + pw < tree.size() and tree[i + pw] < x) {
        i += pw; x -= tree[i];
      }
    } return i;
  } };