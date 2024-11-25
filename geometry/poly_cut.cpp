VP poly_cut(VP &pg, P s, P e) {
  VP cut;
  for (int i = 0; i < pg.size(); ++i) {
    P curr = pg[i], prev = i ? pg[i - 1] : pg.back();
    bool side = s.cross(e, curr) < 0;
    if (side != (s.cross(e, prev) < 0))
      cut.push_back(line_isect(s, e, curr, prev).second);
    if (side) cut.push_back(curr);
  }
  return cut;
}
