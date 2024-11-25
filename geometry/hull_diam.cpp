pair<P, P> hull_diam(VP &hull) {
  int n = hull.size(), j = n < 2 ? 0 : 1;
  pair<D, pair<P, P>> diam({0, {hull[0], hull[0]}});
  for (int i = 0; i < j; ++i) {
    for (;; j = (j + 1) % n) {
      diam = max(diam, {(hull[i] - hull[j]).dist2(), {hull[i], hull[j]}});
      if ((hull[(j + 1) % n] - hull[j]).cross(hull[i + 1] - hull[i]) >= 0)
        break;
    }
  }
  return diam.second;
}
