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
using ld = long double;
// clang-format on

using P = pair<ld, ld>;

int main() {
  // N <= 300
  // N^3 <= 27,000,000
  int n;
  cin >> n;

  vector<P> vp(n);
  rep(i, n) cin >> vp[i].first >> vp[i].second;

  auto calc = [](const P& a, const P& b) -> ld {
    return sqrtl(powl(a.first - b.first, 2) + powl(a.second - b.second, 2));
  };

  int cnt{};

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        ld x = calc(vp[i], vp[j]);
        ld y = calc(vp[j], vp[k]);
        ld z = calc(vp[k], vp[i]);
        // dump(x, y, z);

        dump(x, y, z);
        if ((x + y > z) && (y + z > x) && (z + x > y)) {
          cnt++;
        }
      }
    }
  }

  cout << cnt << el;
}
