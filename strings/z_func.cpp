vi z_func(string &s) {
  int lb = 0, rb = 0;
  vi z(s.size(), 0);
  for (int i = 1; i < s.size(); ++i) {
    if (i <= rb) z[i] = min(z[i - lb], rb - i + 1);
    while (i + z[i] < s.size() and s[i + z[i]] == s[z[i]]) z[i]++;
    if (i + z[i] - 1 > rb) lb = i, rb = i + z[i] - 1;
  }
  return z;
}
vi z_func(string &s, string &t) {
  int lb = 0, rb = 0;
  vi tz(t.size(), 0), z(s.size(), 0);
  for (int i = 1; i < t.size(); ++i) {
    if (i <= rb) tz[i] = min(tz[i - lb], rb - i + 1);
    while (i + tz[i] < t.size() and t[i + tz[i]] == t[tz[i]]) tz[i]++;
    if (i + tz[i] - 1 > rb) lb = i, rb = i + tz[i] - 1;
  }
  while (z[0] < s.size() and z[0] < t.size() and t[z[0]] == s[z[0]]) z[0]++;
  lb = 0, rb = z[0] - 1;
  for (int i = 1; i < s.size(); ++i) {
    if (i <= rb) z[i] = min(tz[i - lb], rb - i + 1);
    while (i + z[i] < s.size() and z[i] < t.size() and s[i + z[i]] == t[z[i]]) z[i]++;
    if (i + z[i] - 1 > rb) lb = i, rb = i + z[i] - 1;
  }
  return z;
}
