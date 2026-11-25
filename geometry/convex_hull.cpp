vector<P> convex_hull(vector<P> ps) {
  sort(all(ps)); ps.erase(unique(all(ps)), ps.end());
  if (ps.size() <= 2) return ps;
  vector<P> lo, hi;
  for (auto p : ps) {
      while (lo.size()>=2 && lo[lo.size() - 2].cross(lo.back(), p)<=0) lo.pop_back();
      lo.push_back(p);
  }
  for (int i = (int)ps.size() - 1; i >= 0; --i) {
      auto p = ps[i];
      while (hi.size()>=2 && hi[hi.size() - 2].cross(hi.back(), p)<=0) hi.pop_back();
      hi.push_back(p);
  }
  if (lo.size() == ps.size()) return ps;
  lo.pop_back(); hi.pop_back(); lo.insert(lo.end(), hi.begin(), hi.end());
  return lo;
}