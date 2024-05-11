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

ll MOD = 100'000'000LL;

int main() {
  int n;
  cin >> n;

  vector<ll> ai(n), acc(n + 1);
  rep(i, n) cin >> ai[i];
  sort(all(ai));
  dump(ai);

  rep(i, n - 1) acc[i + 1] = acc[i] + ai[i];

  ll ans{};

  rep(i, n) {
    int rest = MOD - ai[i];
    auto idx = lower_bound(ai.begin(), ai.end(), rest);
    auto pos = distance(ai.begin(), idx);
    cerr << pos << el;
    dump(rest, pos);
  }

  cout << ans << el;
}
