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

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> ai(n);
  for (auto& a : ai) cin >> a;

  int idx{};
  rep(_, q) {
    int t, x, y;
    cin >> t >> x >> y;
    x--, y--;

    if (t == 1) {
      swap(ai[(x + idx) % n], ai[(y + idx) % n]);
    } else if (t == 2) {
      idx = (idx - 1 + n) % n;
    } else {
      cout << ai[(x + idx) % n] << el;
    }
  }
}
