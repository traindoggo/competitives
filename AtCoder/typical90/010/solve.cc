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

int main() {
  int n;
  cin >> n;

  vector ps(2, vector<int>(n, 0));
  rep(i, n) {
    int c, p;
    cin >> c >> p;
    ps[c - 1][i] = p;
  }

  vector acc(2, vector<int>(n + 1, 0));
  rep(i, n) {
    acc[0][i + 1] = acc[0][i] + ps[0][i];
    acc[1][i + 1] = acc[1][i] + ps[1][i];
  }

  int q;
  cin >> q;
  rep(_, q) {
    int l, r;
    cin >> l >> r;
    int class1 = acc[0][r] - acc[0][l - 1];
    int class2 = acc[1][r] - acc[1][l - 1];
    cout << class1 << ' ' << class2 << el;
  }
}
