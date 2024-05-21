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

int main() {
  int n, m;
  cin >> n >> m;

  vector sw(m, vector<bool>(n, false));
  rep(i, m) {
    int k;
    cin >> k;

    rep(__, k) {
      int s;
      cin >> s;
      sw[i][s - 1] = true;
    }
  }

  vector<int> pi(m);
  rep(i, m) cin >> pi[i];

  int ans{};

  rep(bit, 1 << n) {
    vector<int> ons(m);

    rep(i, n) {
      if (bit & (1 << i)) {
        rep(k, m) {
          if (sw[k][i] == true) {
            ons[k]++;
          }
        }
      }
    }

    // count
    int cnt{};
    rep(i, m) {
      if (ons[i] % 2 == pi[i]) {
        cnt++;
      }
    }
    if (cnt == m) {
      ans++;
    }
  }

  cout << ans << el;
}
