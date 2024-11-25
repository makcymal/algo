pair<P, D> circumcircle(P A, P B, P C) {
  P b = C - A, c = B - A, a = C - B;
  P cen = A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
  D rad = c.dist() * a.dist() * b.dist() / abs(c.cross(b)) / 2;
  return {cen, rad};
}
