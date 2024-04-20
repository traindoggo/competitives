#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

int main() {
  int n;
  cin >> n;

  vector<int> ai(n + 1);
  rep(i, n) cin >> ai[i + 1];

  map<int, int> mp;
  rep(i, n) {
    mp[ai[i + 1]] = i + 1;
  }

  vector<pair<int, int>> ans;

  for (int i = 1; i <= n; ++i) {
    // push ans
    if (ai[i] != i) {
      ans.push_back({i, mp[i]});

      int swapped_idx = mp[i];
      mp[i] = i;
      mp[ai[i]] = swapped_idx;
      swap(ai[i], ai[swapped_idx]);
    }
  }

  cout << ans.size() << el;
  if (ans.size() != 0) {
    for (auto [l, r] : ans) {
      cout << l << ' ' << r << el;
    }
  }
}
