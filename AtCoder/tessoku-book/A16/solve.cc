#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/dump.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define el '\n'
#define rep(i,n) for (int i=0;i<(int)n;++i)
#define die(msg) do{cout<<(msg)<<el;exit(0);}while(0);

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

using ll = long long int;
// clang-format on

int main() {
  int n;
  cin >> n;

  vector<int> ai(n - 1), bi(n - 2);
  rep(i, n - 1) cin >> ai[i];
  rep(i, n - 2) cin >> bi[i];

  dump(ai);
  dump(bi);

  vector<int> dp(n, INFi);
  dp[0] = 0;

  rep(i, n) {
    if (i < n - 1) {
      chmin(dp[i + 1], dp[i] + ai[i]);
    }

    if (i < n - 2) {
      chmin(dp[i + 2], dp[i] + bi[i]);
    }
    dump(dp);
  }

  cout << dp[n - 1] << el;
}
