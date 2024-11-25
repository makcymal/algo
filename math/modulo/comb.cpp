vector<ll> fac(LIM), rev(LIM);
fac[0] = 1;
for (int i = 1; i < LIM; i++) fac[i] = i * fac[i - 1] % MOD;
rev.back() = inv(fac.back())
for (int i = LIM - 1; i >= 1; i--) rev[i-1] = rev[i] * i % MOD;

ll C(int n, int k) { return fac[n] * rev[k] % MOD * rev[n - k] % MOD; }
