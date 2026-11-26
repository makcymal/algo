def find_first_ok(lb, rb, ok):  # 0B, EE
  while lb < rb:
    md = (lb + rb) // 2
    if ok(md): rb = md
    else: lb = md + 1
  return lb
