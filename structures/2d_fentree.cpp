struct Fenwick2D {
  typedef int T;
  vector<vector<T>> tree;
  int y_size, x_size;

  Fenwick2D(int y_sz, int x_sz)
  : y_size(y_sz), x_size(x_sz), tree(y_sz + 1, vector<T>(x_sz + 1, 0)) {}
  T get(int y, int x) { return qry(y, y, x, x); }
  T qry(int yr, int xr) {
    if (yr < 0 or xr < 0) return 0;
    T res = 0;
    for (int iy = yr + 1; iy > 0; iy -= iy & -iy)
      for (int ix = xr + 1; ix > 0; ix -= ix & -ix) res += tree[iy][ix];
    return res;
  }
  T qry(int yl, int yr, int xl, int xr) {
    return qry(yr, xr) - qry(yl - 1, xr) - qry(yr, xl - 1) + qry(yl - 1, xl - 1);
  }
  void upd(int y, int x, T val) {
    for (int iy = y + 1; iy <= y_size; iy += iy & -iy)
      for (int ix = x + 1; ix <= x_size; ix += ix & -ix) tree[iy][ix] += val;
  }
  void set(int y, int x, T val) { upd(y, x, val - get(y, x)); }
};
