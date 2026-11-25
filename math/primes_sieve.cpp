const int LIM = 1e6, SLIM = 1e3;
bitset<LIM> is_prime;
vi eratosthenes() {
  const int R = LIM / 2; vi pr = {2}, sieve(SLIM + 1);
  pr.reserve(int(LIM / log(LIM) * 1.1)); vector<pii> cp;
  for (int i = 3; i <= SLIM; i += 2) if (!sieve[i]) {
    cp.push_back({i, i * i / 2});
    for (int j = i * i; j <= SLIM; j += 2 * i) sieve[j] = 1;
  }
  for (int L = 1; L <= R; L += SLIM) {
    array<bool, SLIM> block{};
    for (auto &[p, idx] : cp)
      for (int i = idx; i < SLIM + L; idx = (i += p)) block[i - L] = 1;
    for (int i = 0; i < min(SLIM, R - L); ++i)
      if (!block[i]) pr.push_back((L + i) * 2 + 1);
  }
  for (int i : pr) is_prime[i] = 1;
  return pr; }
