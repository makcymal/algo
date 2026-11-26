def unbounded_knapsack(items, capacity):
  dp = [0] * (capacity + 1)
  for weight, value in items:
    for c in range(weight, capacity + 1): dp[c] = max(dp[c], dp[c - weight] + value)
  return dp[capacity]