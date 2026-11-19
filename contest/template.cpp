#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,avx2,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;
using vi = vector<int>;
using vll = vector<ll>;
using vull = vector<ull>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;

#define hset unordered_set
#define hmap unordered_map
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SP ' '
#define NL '\n'
#define all(c) (c).begin(), (c).end()

int speedup = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
} ();