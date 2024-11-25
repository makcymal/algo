D poly_area2(VP &pg) {
  D area = pg.back().cross(pg[0]);
  for (int i = 0; i < pg.size() - 1; ++i) area += pg[i].cross(pg[i + 1]);
  return area;
}
