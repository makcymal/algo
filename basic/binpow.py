def binpow(a, b, mod):  # or simply use built-in pow(a, b, mod)
  a %= mod; result = 1 % mod
  while b:
    if b & 1: result = result * a % mod
    a = a * a % mod; b >>= 1
  return result