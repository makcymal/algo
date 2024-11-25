int side_of(P s, P e, P p) {
  D a = (e - s).cross(p - s);
  D q = (e - s).dist() * EPS;
  return (a > q) - (a < -q);
}
