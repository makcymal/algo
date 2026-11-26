def lcs_length(a, b):
  if len(a) < len(b): a, b = b, a
  dp = [0] * (len(b) + 1)
  for x in a:
    diagonal = 0
    for j, y in enumerate(b, 1):
      old = dp[j]
      if x == y: dp[j] = diagonal + 1
      else: dp[j] = max(dp[j], dp[j - 1])
      diagonal = old
  return dp[-1]