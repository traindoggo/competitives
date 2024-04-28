#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0;i<(int)n;++i)
#define die(msg) do{cout<<(msg)<<'\n',exit(0);}while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
#define rall(k) k.rbegin(), k.rend()

#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using llint  = long long int;
// clang-format on

void solve() {
  int n, k;
  cin >> n >> k;

  map<int, int> mp;
  // 100
  rep(i, n) {
    int a;
    cin >> a;
    mp[a]++;
  }

  bool can_exchange{false};
  for (auto [num, cnt] : mp) {
    if (cnt >= k) {
      can_exchange = true;
    }
  }

  if (can_exchange)
    cout << k - 1 << el;
  else
    cout << n << el;
}

int main() {
  // 500
  int t;
  cin >> t;
  while (t--) solve();
}
