VP convex_hull(VP ps) {
  if (ps.size() <= 1) return ps;
  sort(all(ps));
  VP hull(ps.size() + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(ps)))
    for (auto p : ps) {
      while (t >= s + 2 and hull[t - 2].cross(hull[t - 1], p) <= 0) t--;
      hull[t++] = p;
    }
  return {hull.begin(), hull.begin() + t - (t == 2 and hull[0] == hull[1])};
}
