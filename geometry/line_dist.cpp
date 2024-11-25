D line_dist(P s, P e, P p) {
  assert(s != e);
  return (e - s).cross(p - s) / (e - s).dist();
}
