int LIM;
struct Power {
  ll B, M;
  vector<ll> val;
  Power(ll B, ll M) : B(B), M(M), val(LIM + 1) {
    val[0] = 1;
    for (int i = 1; i <= LIM; ++i) val[i] = (val[i - 1] * B) % M;
  }
  ll operator()(size_t i) { return val[i]; };
};
struct Hasher {
  Power &pw1, &pw2;
  vector<ll> ha1, ha2;
  Hasher(Power &pw1, Power &pw2, string &s)
  : pw1(pw1), pw2(pw2), ha1(s.size() + 1), ha2(s.size() + 1) {
    ha1[0] = ha2[0] = 0;
    for (int i = 1; i <= s.size(); ++i) {
      ha1[i] = (ha1[i - 1] + (s[i - 1] - 'a' + 1) * pw1(i)) % pw1.M;
      ha2[i] = (ha2[i - 1] + (s[i - 1] - 'a' + 1) * pw2(i)) % pw2.M;
    }
  }
  pll operator()(int l, int r) {
    return {
      ((ha1[r + 1] + pw1.M - ha1[l]) % pw1.M) * pw1(LIM - r) % pw1.M,
      ((ha2[r + 1] + pw2.M - ha2[l]) % pw2.M) * pw2(LIM - r) % pw2.M,
    };
  }
};
