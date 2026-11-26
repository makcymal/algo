def offline_segments_sum(n, updates):   # 0B, EE
  d = [0] * (n + 1)
  for l, r, x in updates: d[l] += x; d[r] -= x
  result, total = [], 0
  for i in range(n): total += d[i]; result.append(total)
  return result