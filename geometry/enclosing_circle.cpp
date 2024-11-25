pair<P, D> enclosing_circle(VP &ps) {
  shuffle(all(ps), mt19937(time(0)));
  P cen = ps[0];
  D rad = 0, eps = 1 + 1e-8;
  for (int i = 0; i < ps.size(); ++i) {
    if ((cen - ps[i]).dist() > rad * eps) {
      cen = ps[i], rad = 0;
      for (int j = 0; j < i; ++j)
        if ((cen - ps[j]).dist() > rad * eps) {
          cen = (ps[i] + ps[j]) / 2;
          rad = (cen - ps[i]).dist();
          for (int k = 0; k < j; ++k)
            if ((cen - ps[k]).dist() > rad * eps) {
              cen = circumcircle(ps[i], ps[j], ps[k]).first;
              rad = (cen - ps[i]).dist();
            }
        }
    }
  }
  return {cen, rad};
}
