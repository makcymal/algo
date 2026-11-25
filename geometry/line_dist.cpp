D line_dist(P s, P e, P p) {  // s != e
  return (e - s).cross(p - s) / (e - s).dist();
}
