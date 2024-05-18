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

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using ll = long long int;
// clang-format on

int main() {
  // n <= 2*10^5
  // a, b <= 2*10^5
  // L < R < L + n
  // L < n
  // x < n
  ll n, a, b, l, r, x;
  cin >> n >> a >> b >> l >> r >> x;

  auto gen = [&](ll rk) { return (((a % n) * (rk % n)) % n + b) % n; };

  // num index
  map<ll, ll> mp;
  ll rk{l};
  rep(i, 200'001) {
    if (i == 0) {
      mp[l] = 0;
    } else {
      rk = gen(rk);
      if (mp.find(rk) != mp.end()) break;
      mp[rk] = i;
    }
  }

  if (mp.find(x) == mp.end()) {
    die(-1);
  }

  ll size = (int)mp.size();
  ll ans{INFi};

  for (ll i = l; i < r; ++i) {
    if (mp[i] < mp[x]) {
      chmin(ans, mp[x] - mp[i]);
    } else {
      chmin(ans, mp[i] + (size - mp[x]));
    }
  }

  cout << ans << el;
}
