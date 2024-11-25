void cw_order(VP &ps) {
  P cen = ps[0];
  auto cmp = [&](P &a, P &b) {
    return (a == cen ? M_PI : (a - cen).angle()) >
           (b == cen ? M_PI : (b - cen).angle());
  };
  sort(all(ps), cmp);
}
