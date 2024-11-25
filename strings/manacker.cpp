vi manacker_odd(string &s) {
  vi rad(s.size(), 1);
  int lb = 0, rb = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (i <= rb) rad[i] = min(rad[lb + rb - i], rb - i + 1);
    while (0 <= i - rad[i] and i + rad[i] < s.size() and
           s[i - rad[i]] == s[i + rad[i]]) rad[i]++;
    if (rb < i + rad[i] - 1) lb = i - rad[i] + 1, rb = i + rad[i] - 1;
  }
  return rad;
}
vi manacker_even(string &s) {
  vi rad(s.size() - 1, 0);
  int lb = -1, rb = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (i <= rb) rad[i] = min(rad[lb + rb - i - 1], rb - i);
    while (0 <= i - rad[i] and i + rad[i] - 1 < s.size() and
           s[i - rad[i]] == s[i + rad[i] - 1]) rad[i]++;
    if (rb < i + rad[i]) lb = i - rad[i] + 1, rb = i + rad[i];
  }
  return rad;
}
