struct Poly {
  typedef double D;
  typedef vector<D> vd;
  vd cf;
  
  Poly(vd &_cf) : cf(_cf) {}
  Poly(vd &x, vd &y) {
    int n = x.size();
    cf.resize(n);
    vd temp(n);
    for (int k = 0; k < n - 1; ++k)
      for (int i = k + 1; i < n; ++i) y[i] = (y[i] - y[k]) / (x[i] - x[k]);
    double last = 0;
    temp[0] = 1;
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        cf[i] += y[k] * temp[i];
        swap(last, temp[i]);
        temp[i] -= last * x[k];
      }
    }
  }
  double eval(double x) {
    double y = 0;
    for (int i = cf.size() - 1; i >= 0; --i) (y *= x) += cf[i];
    return y;
  }
  void diff() {
    for (int i = 1; i < cf.size(); ++i) cf[i - 1] = i * cf[i];
    cf.pop_back();
  }
  // may give more roots to left or to the right
  vd roots(double xmin, double xmax) {
    if (cf.size() == 2) return {-cf[0] / cf[1]};
    vd roots;
    Poly deriv(*this);
    deriv.diff();
    vd dr = deriv.roots(xmin, xmax);
    dr.push_back(xmin - 1);
    dr.push_back(xmax + 1);
    sort(dr.begin(), dr.end());
    for (int i = 0; i < dr.size() - 1; ++i) {
      double lb = dr[i], rb = dr[i + 1];
      bool sign = eval(lb) > 0;
      if (sign ^ (eval(rb) > 0)) {
        for (int it = 0; it < 60; ++it) {
          double md = (lb + rb) / 2;
          if ((eval(md) <= 0) ^ sign) lb = md;
          else rb = md;
        }
        roots.push_back((lb + rb) / 2);
      }
    }
    return roots;
  }
};
