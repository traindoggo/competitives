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

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using ll = long long int;
// clang-format on

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  // q <= 5 * 10^5
  rep(_, q) {
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;

    // r <= 5 * 10^5
    int cnt{};
    for (int i = l; i <= r; ++i) {
      if (ai[i] % k == 0) cnt++;
    }
    cout << cnt << el;
  }
}
