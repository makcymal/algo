struct Fenwick2D {
  int y_size, x_size; vector<vector<T>> tree;
  Fenwick2D(int y_sz, int x_sz)
    : y_size(y_sz), x_size(x_sz), tree(y_sz + 1, vector<T>(x_sz + 1, 0)) {}
  T query(int yr, int xr) {
    T res = 0;
    for (int iy = yr + 1; iy > 0; iy -= iy & -iy)
      for (int ix = xr + 1; ix > 0; ix -= ix & -ix) res += tree[iy][ix];
    return res;
  }
  T query(int yl, int yr, int xl, int xr) {
    return query(yr,xr) - query(yl - 1,xr) - query(yr,xl - 1) + query(yl - 1,xl - 1);
  }
  void update(int y, int x, T val) {
    for (int iy = y + 1; iy <= y_size; iy += iy & -iy)
      for (int ix = x + 1; ix <= x_size; ix += ix & -ix) tree[iy][ix] += val;
  } };