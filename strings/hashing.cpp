int LIM;

struct Power {
  ll B, M;
  vector<ll> val;

  Power(ll B, ll M) : B(B), M(M), val(LIM + 1) {
    val[0] = 1;
    for (int i = 1; i <= LIM; ++i) val[i] = (val[i - 1] * B) % M;
  }

  ll operator()(size_t i) {
    return val[i];
  };
};

struct Hasher {
  Power &pw1, &pw2;
  vector<ll> ha1, ha2;

  Hasher(Power &pw1, Power &pw2, string &s)
  : pw1(pw1), pw2(pw2), ha1(s.size()), ha2(s.size()) {
    ha1[0] = (s[0] - 'a' + 1) * pw1(1);
    ha2[0] = (s[0] - 'a' + 1) * pw2(1);
    for (int i = 1; i < s.size(); ++i) {
      ha1[i] = (ha1[i - 1] + (s[i] - 'a' + 1) * pw1(i + 1)) % pw1.M;
      ha2[i] = (ha2[i - 1] + (s[i] - 'a' + 1) * pw2(i + 1)) % pw2.M;
    }
  }

  pll operator()(int lb, int rb) {
    auto ha1lb = (lb == 0 ? 0 : ha1[lb - 1]), ha2lb = (lb == 0 ? 0 : ha2[lb - 1]);
    return {
      ((ha1[rb] + pw1.M - ha1lb) % pw1.M) * pw1(LIM - rb) % pw1.M,
      ((ha2[rb] + pw2.M - ha2lb) % pw2.M) * pw2(LIM - rb) % pw2.M,
    };
  }

  pll operator()(string &s) {
    ll h1 = (s[0] - 'a' + 1) * pw1(1);
    ll h2 = (s[0] - 'a' + 1) * pw2(1);
    for (int i = 1; i < s.size(); ++i) {
      h1 = (h1 + (s[i] - 'a' + 1) * pw1(i + 1)) % pw1.M;
      h2 = (h2 + (s[i] - 'a' + 1) * pw2(i + 1)) % pw2.M;
    }
    return {
      h1 * pw1(LIM - s.size() + 1) % pw1.M,
      h2 * pw2(LIM - s.size() + 1) % pw2.M,
    };
  }
};