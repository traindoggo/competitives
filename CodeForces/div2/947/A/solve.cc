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
#define rep(gg,n) for(int gg=0;gg<(int)n;++gg)
#define die(msg) cout<<(msg)<<el;exit(0);

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

void solve() {
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  rep(i, n) {
    vector<int> tmp;
    for (int k = 1; k < n; ++k) {
      tmp.push_back(ai[k]);
    }
    tmp.push_back(ai.front());

    bool is_sorted{true};
    rep(j, n - 1) {
      if (tmp[j] > tmp[j + 1]) {
        is_sorted = false;
      }
    }

    if (is_sorted) {
      cout << "Yes" << el;
      return;
    }

    ai = tmp;
  }

  cout << "No" << el;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
}
