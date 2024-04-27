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
using ld = long double;
// clang-format on

int main() {
  int n, k;
  cin >> n >> k;

  vector<ld> pi(n);
  rep(i, n) cin >> pi[i];

  vector<ld> expects(n);
  rep(i, n) expects[i] = (1 + pi[i]) / 2;

  dump(expects);

  // この計算だとだいぶ誤差出る気がする
  // 整数値で計算する方法があるはず
  ld ans{}, cur{};
  rep(i, k) cur += expects[i];
  chmax(ans, cur);

  for (int i = k; i < n; ++i) {
    cur += expects[i];
    cur -= expects[i - k];
    chmax(ans, cur);
  }

  cout << fixed << setprecision(12);
  cout << ans << el;
}
