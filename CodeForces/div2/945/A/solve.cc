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

void solve() {
  vector<int> pi(3);
  rep(i, 3) cin >> pi[i];

  auto is_zero = [&](int i1, int i2) { return pi[i1] <= 0 && pi[i2] <= 0; };

  int cnt{};
  while (true) {
    if (is_zero(0, 1) || is_zero(1, 2) || is_zero(2, 0)) break;

    sort(all(pi));

    if (pi[2] >= 1 && pi[1] >= 1) {
      pi[2]--;
      pi[1]--;
      cnt++;
    }
  }

  rep(i, 3) {
    if (pi[i] % 2 == 1) {
      cout << -1 << el;
      return;
    }
  }

  cout << cnt << el;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
