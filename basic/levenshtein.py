def levenshtein(a, b):
  if len(a) < len(b): a, b = b, a
  dp = list(range(len(b) + 1))
  for i, x in enumerate(a, 1):
    diagonal, dp[0] = dp[0], i
    for j, y in enumerate(b, 1):
      old = dp[j]
      dp[j] = min(dp[j] + 1, dp[j - 1] + 1, diagonal + (x != y))
      diagonal = old
  return dp[-1]