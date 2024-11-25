bool circle_isect(P c1, D r1, P c2, D r2, pair<P, P> *out) {
  if (c1 == c2) {
    assert(r1 != r2);
    return false;
  }
  P vec = c2 - c1;
  D d2 = vec.dist2(), sum = r1 + r2, dif = r1 - r2,
    p = (d2 + r1 * r1 - r2 * r2) / (d2 * 2), h2 = r1 * r1 - p * p * d2;
  if (sum * sum < d2 or dif * dif > d2) return false;
  P mid = c1 + vec * p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
  *out = {mid + per, mid - per};
  return true;
}
