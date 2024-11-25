ull modmul(ull a, ull b, ull mod) {
  ll ret = a * b - mod * ull(1.L / mod * a * b);
  return ret + mod * (ret < 0) - mod * (ret >= (ll)mod);
}
