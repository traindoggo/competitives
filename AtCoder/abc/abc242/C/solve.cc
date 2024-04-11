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

void Add(llint& x, llint y) {
  x += y;
  x %= MOD98;
}

int main() {
  int n;
  cin >> n;

  vector dp(n + 2, vector<llint>(10, 0));
  for (int d = 1; d <= 9; ++d) {
    dp[1][d] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    for (int d = 1; d <= 9; ++d) {
      if (d - 1 >= 1) Add(dp[i][d], dp[i - 1][d - 1]);
      Add(dp[i][d], dp[i - 1][d]);
      if (d + 1 <= 9) Add(dp[i][d], dp[i - 1][d + 1]);
    }
  }

  llint ans{};
  for (int d = 1; d <= 9; ++d) {
    Add(ans, dp[n][d]);
  }
  cout << ans << el;
}
