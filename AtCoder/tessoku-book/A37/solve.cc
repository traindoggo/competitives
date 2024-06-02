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
  ll n, m, b;
  cin >> n >> m >> b;

  vector<ll> ai(n), ci(m);
  rep(i, n) cin >> ai[i];
  rep(i, m) cin >> ci[i];

  dump(ai);
  dump(ci);

  ll ans{};

  ll sum_c{};
  for (const ll& c : ci) sum_c += c;
  for (const ll& a : ai) {
    ans += (a + b) * m + sum_c;
  }

  cout << ans << el;
}
