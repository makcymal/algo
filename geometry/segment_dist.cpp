D segment_dist(P s, P e, P p) {
  if (s == e) return (p - s).dist();
  D d = (e - s).dist2(), t = min(d, max(.0, (p - s).dot(e - s)));
  return ((p - s) * d - (e - s) * t).dist() / d;
}
