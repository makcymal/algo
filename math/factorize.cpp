ull pollard(ull num) {
  ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
  auto f = [&](ull x) { return modmul(x, x, num) + i; };
  while (t++ % 40 or __gcd(prd, num) == 1) {
    if (x == y) x = ++i, y = f(x);
    if ((q = modmul(prd, max(x, y) - min(x, y), num))) prd = q;
    x = f(x), y = f(f(y));
  }
  return __gcd(prd, num);
}
vector<ull> factor(ull num) {
  if (num == 1) return {};
  if (is_prime(num)) return {num};
  ull x = pollard(num);
  auto L = factor(x), R = factor(num / x);
  L.insert(L.end(), all(R));
  return L;
}
