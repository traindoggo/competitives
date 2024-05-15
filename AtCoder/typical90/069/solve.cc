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

using ll = long long int;
// clang-format on

// x^n % MOD
ll modpow(ll x, ll n, ll mod) {
  x %= mod;

  // x^0 == 1
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return modpow(x * x, n / 2, mod) % mod;
  } else {
    return (x * modpow(x, n - 1, mod)) % mod;
  }
}

int main() {
  ll n, k;
  cin >> n >> k;

  ll ans{1};

  // [k]
  if (n == 1) {
    ans = k;
  }

  // [k][k-1]
  if (n == 2) {
    ans = k * (k - 1);
  }

  // [k][k-1] [k-2][k-2][...] (n-2)
  if (n >= 3) {
    ans = (k * (k - 1) % MOD17) * modpow(k - 2, n - 2, MOD17);
  }

  cout << ans % MOD17 << el;
}
