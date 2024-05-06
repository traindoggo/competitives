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

namespace me {
int lower_bound(const vector<ll>& a, ll key) {
  int l{-1};
  int r{(int)a.size()};

  while (r - l > 1) {
    int mid = l + (r - l) / 2;

    if (a[mid] >= key) {
      r = mid;
    } else {
      l = mid;
    }
  }

  return r;
}
}  // namespace me

int main() {
  int n;
  cin >> n;

  vector<ll> ai(n);
  rep(i, n) cin >> ai[i];
  sort(ai.begin(), ai.end());

  int q;
  cin >> q;
  rep(_, q) {
    ll b;
    cin >> b;

    ll res = INFi;

    int idx = me::lower_bound(ai, b);
    if (idx < n) {
      chmin(res, abs(ai[idx] - b));
    }

    if (0 < idx) {
      chmin(res, abs(ai[idx - 1] - b));
    }

    cout << res << el;
  }
}
