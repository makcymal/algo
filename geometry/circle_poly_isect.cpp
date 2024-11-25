#define arg(p, q) atan2((p).cross(q), (p).dot(q))
D circle_poly_isect(P c, D a, VP &pg) {
  auto tri = [&](P p, P q) {
    auto r2 = a * a / 2;
    P d = q - p;
    auto a = d.dot(p) / d.dist2(), b = (p.dist2() - a * a) / d.dist2();
    auto det = a * a - b;
    if (det <= 0) return arg(p, q) * r2;
    auto s = max(0., -a - sqrt(det)), t = min(1., -a + sqrt(det));
    if (t < 0 or 1 <= s) return arg(p, q) * r2;
    P u = p + d * s, v = p + d * t;
    return arg(p, u) * r2 + u.cross(v) / 2 + arg(v, q) * r2;
  };
  auto area = 0.;
  for (int i = 0; i < pg.size(); ++i)
    area += tri(pg[i] - c, pg[(i + 1) % pg.size()] - c);
  return area;
}
