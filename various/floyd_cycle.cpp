pii floyd_cycle(int x) {
  int tort = f(x), hare = f(f(x)), len = 1, pos = 0;
  while (tort != hare) tort = f(tort), hare = f(f(hare));
  tort = x;
  while (tort != hare) tort = f(tort), hare = f(hare),pos++;
  hare = f(hare);
  while (tort != hare) hare = f(hare), len++;
  return {len, pos}
}
