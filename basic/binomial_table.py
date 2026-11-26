def binomial_table(n_max, mod):
  fact = [1] * (n_max + 1)
  for i in range(1, n_max + 1): fact[i] = fact[i - 1] * i % mod
  invfact = [1] * (n_max + 1); invfact[n_max] = pow(fact[n_max], mod - 2, mod)
  for i in range(n_max, 0, -1): invfact[i - 1] = invfact[i] * i % mod
  def choose(n, k):
    if k < 0 or k > n: return 0
    return fact[n] * invfact[k] % mod * invfact[n-k] % mod
  return choose