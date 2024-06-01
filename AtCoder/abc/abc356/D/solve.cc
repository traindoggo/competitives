#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
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
  ll n, m;
  cin >> n >> m;
  if (n == 0 || m == 0) die(0);

  ll ans{};
  ll weight{2};

  while (m > 0) {
    if ((m & 1) == 1) {
      ans += (n + 1) / weight * (weight / 2);

      ll mod = (n + 1) % weight;
      if (mod != 0 && mod - weight / 2 > 0) {
        ans += mod - weight / 2;
      }
    }
    ans %= MOD98;
    weight *= 2;

    m >>= 1;
  }

  cout << ans % MOD98 << el;
}
