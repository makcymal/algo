pair<int, P> line_isect(P s1, P e1, P s2, P e2) {
  auto d = (e1 - s1).cross(e2 - s2);
  if (d == 0) return {-(s1.cross(e1, s2) == 0), P(0, 0)};
  auto p = s2.cross(e1, s2), q = s2.cross(e2, s1);
  return {1, (s1 * p + e1 * q) / d};
}
