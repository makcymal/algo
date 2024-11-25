P poly_center(VP &pg) {
  P cen(0, 0);
  D area = 0;
  for (int i = 0, j = pg.size() - 1; i < pg.size(); j = i++) {
    cen = cen + (pg[i] + pg[j]) * pg[j].cross(pg[i]);
    area += pg[j].cross(pg[i]);
  }
  return cen / area / 3;
}
