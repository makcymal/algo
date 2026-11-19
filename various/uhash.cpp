struct uhash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }

  static uint64_t seed() {
    static const uint64_t S = chrono::steady_clock::now().time_since_epoch().count();
    return S;
  }

  static uint64_t combine(uint64_t h, uint64_t x) {
    return splitmix64(h * 0x9e3779b97f4a7c15ULL + x);
  }

  template <class T, typename enable_if<is_integral<T>::value, int>::type = 0>
  static uint64_t h(const T& x) {
    return splitmix64(uint64_t(x) + seed());
  }

  template <class A, class B>
  static uint64_t h(const pair<A, B>& p) {
    return combine(h(p.first), h(p.second));
  }

  template <class Tuple, size_t... I>
  static uint64_t tuple_h(const Tuple& t, index_sequence<I...>) {
    uint64_t r = seed();
    int dummy[] = {0, ((r = combine(r, h(get<I>(t)))), 0)...};
    (void)dummy;
    return r;
  }
  
  template <class... Ts>
  static uint64_t h(const tuple<Ts...>& t) {
    return tuple_h(t, index_sequence_for<Ts...>());
  }

  template <class T>
  static uint64_t h(const vector<T>& v) {
    uint64_t r = splitmix64(v.size() + seed());
    for (size_t i = 0; i < v.size(); i++) r = combine(r, h(v[i]));
    return r;
  }

  static uint64_t h(const string& s) {
    uint64_t r = splitmix64(s.size() + seed());
    for (size_t i = 0; i < s.size(); i++) r = combine(r, (unsigned char)s[i]);
    return r;
  }

  template <class T>
  size_t operator()(const T& x) const { return (size_t)h(x); }
};