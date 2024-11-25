struct RMQ {
  typedef int T;
  vector<vector<T>> seg;
  RMQ(vector<T> &data) : seg(1, data) {
    for (int pw = 1, k = 1; 2 * pw <= data.size(); pw *= 2, ++k) {
      seg.emplace_back(data.size() - 2 * pw + 1);
      for (int i = 0; i < seg.back().size(); ++i)
        seg[k][i] = min(seg[k - 1][i], seg[k - 1][i + pw]);
    }
  }
  T qry(int lb, int rb) {
    int pw = 31 - __builtin_clz(rb - lb);
    return min(seg[pw][lb], seg[pw][rb - (1 << pw)]);
  }
};
