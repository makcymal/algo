set<pii>::iterator add_interval(set<pii> &intervals, int lb, int rb, int &len) {
  if (lb == rb) return intervals.end();
  auto it = intervals.lower_bound({lb, rb}), before = it;
  while (it != intervals.end() && it->first <= rb) {
    rb = max(rb, it->second); len -= it->S - it->F; before = it = intervals.erase(it);
  }
  if (it != intervals.begin() && (--it)->second >= lb) {
    lb = min(lb, it->first); rb = max(rb, it->second);
    len -= it->S - it->F; intervals.erase(it);
  }
  len += rb - lb;
  return intervals.insert(before, {lb, rb});
}
void remove_interval(set<pii> &intervals, int lb, int rb, int &len) {
  if (lb == rb) return;
  auto it = add_interval(intervals, lb, rb, len); auto r2 = it->second;
  if (it->first == lb) { len -= it->S - it->F; intervals.erase(it); }
  else { len += lb - it->S; (int &) it->second = lb; }
  if (rb != r2) { len += r2 - rb; intervals.emplace(rb, r2); }
}