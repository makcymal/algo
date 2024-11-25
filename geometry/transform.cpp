P transform(P s1, P e1, P s2, P e2, P p) {
  P d1 = e1 - s1, d2 = e2 - s2, num(d1.cross(d2), d1.dot(d2));
  return s2 + P((p - s1).cross(num), (p - s1).dot(num)) / d1.dist2();
}
