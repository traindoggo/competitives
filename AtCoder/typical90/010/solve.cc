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
  int n;
  cin >> n;

  vector<int> c1(n), c2(n);
  rep(i, n) {
    int c, b;
    cin >> c >> b;

    if (c == 1) {
      c1[i] = b;
    } else {
      c2[i] = b;
    }
  }
  vector<int> acc1(n + 1), acc2(n + 1);
  rep(i, n) acc1[i + 1] = acc1[i] + c1[i];
  rep(i, n) acc2[i + 1] = acc2[i] + c2[i];

  int q;
  cin >> q;
  rep(_, q) {
    int l, r;
    cin >> l >> r;

    int sum1 = acc1[r] - acc1[l - 1];
    int sum2 = acc2[r] - acc2[l - 1];
    cout << sum1 << ' ' << sum2 << el;
  }
}
