#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
using namespace atcoder;

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

using mint = modint;

int main() {
  ll n, p, q;
  cin >> n >> p >> q;

  vector<ll> ai(n);
  rep(i, n) cin >> ai[i];

  mint ans;
  ans.set_mod((int)p);
  ll cnt{};

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        for (int l = k + 1; l < n; ++l) {
          for (int m = l + 1; m < n; ++m) {
            ans = ai[i];
            ans = ans * ai[j] * ai[k] * ai[l] * ai[m];
            if (ans == q) {
              cnt++;
            }
          }
        }
      }
    }
  }

  cout << cnt << el;
}
