def min_coins(coins, target):
  inf = target + 1; dp = [0] + [inf] * target
  for total in range(1, target + 1):
    for coin in coins:
      if coin <= total: dp[total] = min(dp[total], dp[total - coin] + 1)
  return dp[target] if dp[target] != inf else -1