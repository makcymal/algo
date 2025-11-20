ll modinv(ll a) {
  ll x, y;
  ll d = euclid(a, MOD, x, y);
  return (x + MOD) % MOD;
}
