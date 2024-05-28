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

map<ll, ll> factorize(ll n) {
  map<ll, ll> mp;
  for (ll i = 2; i * i <= n; ++i) {
    ll cnt{};
    while (n % i == 0) {
      cnt++;
      n /= i;
    }
    mp[i] = cnt;
  }

  if (n != 1) mp[n]++;
  return mp;
}

ll nCr(ll n, ll r) {
  map<ll, ll> nume;
  for (ll i = n; i > n - r; --i) {
    auto mp = factorize(i);
    for (auto& [num, cnt] : mp) {
      nume[num] += cnt;
    }
  }

  map<ll, ll> deno;
  for (ll i = 1; i <= r; ++i) {
    auto mp = factorize(i);
    for (auto& [num, cnt] : mp) {
      deno[num] += cnt;
    }
  }

  for (auto& [num, cnt] : deno) {
    nume[num] -= cnt;
  }

  ll ans{1};
  for (auto& [num, cnt] : nume) {
    rep(_, cnt) ans *= num;
  }
  return ans;
}

int main() {
  ll n, r;
  cin >> n >> r;

  ll ans = nCr(n, r);
  cout << ans << el;
}
