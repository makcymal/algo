bool inside_poly(VP &pg, P a, bool strict = true) {
  int cnt = 0, n = pg.size();
  for (int i = 0; i < n; ++i) {
    P &q = pg[(i + 1) % n];
    if (segment_dist(pg[i], q, a) <= EPS) return !strict;
    cnt ^= ((a.y < pg[i].y) - (a.y < q.y)) * a.cross(pg[i], q) > 0;
  }
  return cnt;
}
