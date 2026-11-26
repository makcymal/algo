def previous_smaller(a):
  stack, answer = [], []
  for i, x in enumerate(a):
    while stack and a[stack[-1]] >= x: stack.pop()
    answer.append(stack[-1] if stack else -1)
    stack.append(i)
  return answer