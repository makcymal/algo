struct Compressor {
  int n_orig, n_uniq;
  vector<T> &orig; vector<T> uniq, rank;
  Compressor(vector<T> &orig) 
  : n_orig(orig.size()), orig(orig), uniq(orig), rank(orig.size()) {
    sort(all(uniq)); uniq.erase(unique(all(uniq)), uniq.end()); n_uniq = uniq.size();
    for (int i = 0; i < orig.size(); ++i) rank[i] = get_rank(orig[i]);
  }
  T get_rank(int val) {   // -1 if orig doesn't contain val
    auto lb = lower_bound(all(uniq), val);
    return lb != uniq.end() and *lb == val ? lb - uniq.begin() : -1;
  }
};