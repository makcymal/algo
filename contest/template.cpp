#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vpii = vector<pair<int, int>>;
#define hset unordered_set
#define hmap unordered_map
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define SP ' '
#define NL '\n'
#define all(c) (c).begin(), (c).end()

ios::sync_with_stdio(false);
cin.tie(0); cout.tie(0);
cin.exceptions(cin.failbit);
