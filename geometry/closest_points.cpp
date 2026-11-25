pair<P, P> closest_points(VP ps) {
  assert(ps.size() > 1); set<P> s;
  sort(all(ps), [](P &a, P &b) { return a.y < b.y; });
  pair<D, pair<P, P>> clos{numeric_limits<D>::max(), {P(), P()}};
  int j = 0;
  for (auto &p : ps) {
    P d{1. + sqrt(clos.first), 0.};
    while (ps[j].y <= p.y - d.x) s.erase(ps[j++]);
    auto lo = s.lower_bound(p - d), hi = s.upper_bound(p + d);
    for (; lo != hi; ++lo) clos = min(clos, {(*lo - p).dist2(), {*lo, p}});
    s.insert(p);
  } return clos.second;
}
