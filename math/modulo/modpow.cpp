ull modpow(ull a, ull b, ull mod) {
  ull ret = 1;
  for (; b; a = modmul(a, a, mod), b /= 2)
    if (b & 1) ret = modmul(ret, a, mod);
  return ret;
}
