ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool is_prime(ull num) {
  if (num < 2 or num % 6 % 4 != 1) return (num | 1) == 3;
  ull s = __builtin_ctzll(num - 1);
  ull d = num >> s;
  for (ull a: A) {
    ull p = modpow(a % num, d, num), i = s;
    while (p != 1 and p != num - 1 and a % num and i--)
      p = modmul(p, p, num);
    if (p != num - 1 and i != s) return false;
  }
  return true;
}
