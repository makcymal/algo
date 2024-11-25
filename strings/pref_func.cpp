vi pref_func(string &s) {
  vi pref(s.size(), 0);
  for (int i = 1; i < s.size(); ++i) {
    int c = pref[i - 1];
    while (c > 0 and s[i] != s[c]) c = pref[c - 1];
    if (s[i] == s[c]) pref[i] = c + 1;
  }
  return pref;
}
vi pref_func(string &s, string &t) {
  vi t_pref(t.size(), 0), pref(s.size(), 0);
  for (int i = 1; i < t.size(); ++i) {
    int c = t_pref[i - 1];
    while (c > 0 and t[i] != t[c]) c = t_pref[c - 1];
    if (t[i] == t[c]) t_pref[i] = c + 1;
  }
  if (!s.empty() and !t.empty()) pref[0] = (s[0] == t[0]) ? 1 : 0;
  for (int i = 1; i < s.size(); ++i) {
    int c = pref[i - 1];
    while (c > 0 and s[i] != t[c] or c == t.size()) c = t_pref[c - 1];
    if (s[i] == t[c]) pref[i] = c + 1;
  }
  return pref;
}
