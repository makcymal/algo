VP segment_isect(P s1, P e1, P s2, P e2) {
  D os1 = s2.cross(e2, s1), oe1 = s2.cross(e2, e1);
  D os2 = s1.cross(e1, s2), oe2 = s1.cross(e1, e2);
  if (sgn(os1) * sgn(oe1) < 0 and sgn(os2) * sgn(oe2) < 0)
    return {(s1 * oe1 - e1 * os1 / (oe1 - os1))};
  set<P> s;
  if (segment_dist(s2, e2, s1) <= EPS) s.insert(s1);
  if (segment_dist(s2, e2, e1) <= EPS) s.insert(e1);
  if (segment_dist(s1, e1, s2) <= EPS) s.insert(s2);
  if (segment_dist(s1, e1, e2) <= EPS) s.insert(e2);
  return {all(s)};
}
