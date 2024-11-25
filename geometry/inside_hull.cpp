bool inside_hull(VP &hull, P p, bool strict = true) {
  int a = 1, b = hull.size() - 1, r = !strict;
  if (hull.size() < 3)
    return r and segment_dist(hull[0], hull.back(), p) <= EPS;
  if (side_of(hull[0], hull[a], hull[b]) > 0) swap(a, b);
  if (side_of(hull[0], hull[a], p) >= r or side_of(hull[0], hull[b], p) <= -r)
    return false;
  while (abs(a - b) > 1) {
    int c = (a + b) / 2;
    (side_of(hull[0], hull[c], p) > 0 ? b : a) = c;
  }
  return sgn(hull[a].cross(hull[b], p)) < r;
}
