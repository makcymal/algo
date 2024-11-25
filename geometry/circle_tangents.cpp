vector<pair<P, P>> circle_tangents(P c1, D r1, P c2, D r2) {
  P d = c2 - c1;
  D dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
  if (d2 == 0 or h2 < 0) return {};
  vector<pair<P, P>> tan;
  for (D sign : {-1, 1}) {
    P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
    tan.push_back({c1 + v * r1, c2 + v * r2});
  }
  if (h2 == 0) tan.pop_back();
  return tan;
}
