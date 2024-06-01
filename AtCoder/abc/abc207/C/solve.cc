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

using P = pair<ll, ll>;

int main() {
  int n;
  cin >> n;

  vector<P> vt(n);
  rep(i, n) {
    ll t, l, r;
    cin >> t >> l >> r;

    if (t == 1) {
      l = 2 * l;
      r = 2 * r + 1;
    } else if (t == 2) {
      l = 2 * l;
      r = 2 * r;
    } else if (t == 3) {
      l = 2 * l + 1;
      r = 2 * r + 1;
    } else {
      l = 2 * l + 1;
      r = 2 * r;
    }
    vt[i] = make_pair(l, r);
  }

  for (auto [l, r] : vt) {
    dump(l, r);
  }

  ll ans{};
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      P left = vt[i], right = vt[j];

      if (!(left.second < right.first || right.second < left.first)) {
        ans++;
      }
    }
  }
  cout << ans << el;
}
