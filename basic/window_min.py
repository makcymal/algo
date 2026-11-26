from collections import deque
def window_min(a, k):
  q, answer = deque(), []
  for i, x in enumerate(a):
    while q and q[0] <= i - k: q.popleft()
    while q and a[q[-1]] >= x: q.pop()
    q.append(i)
    if i >= k - 1: answer.append(a[q[0]])
  return answer