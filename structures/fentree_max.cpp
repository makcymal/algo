struct Fentree {
  typedef int T;
  int size; vector<T> data, tree;
  Fentree(int sz, T def = 0) : size(sz), data(sz + 1, 0), tree(sz + 1, def) { }
  T query(int lb, int rb) {
    T res = 0; lb++; rb++;  // res is same as def
    for (int i = rb; i >= lb;) {
      if (i - (i & -i) + 1 >= lb) { res = max(res, tree[i]); i -= (i & -i); }
      else { res = max(res, data[i]); i -= 1; }
    } return res;
  }
  void update(int i, T val) {   // only increased val allowed 
    i++; data[i] = max(data[i],val);
    for (; i <= size; i += (i & -i)) tree[i] = max(tree[i], val);
  } };