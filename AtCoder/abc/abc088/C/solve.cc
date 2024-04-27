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

using llint  = long long int;
// clang-format on

int main() {
  vector grid(3, vector<int>(3, 0));
  rep(i, 3) rep(j, 3) cin >> grid[i][j];

  // horizontal
  rep(i, 3) {
    int maxv{101};
    rep(j, 3) {
      chmin(maxv, grid[i][j]);
    }

    rep(j, 3) {
      grid[i][j] -= maxv;
    }
  }

  // search vertical
  bool is_ok{true};
  rep(x, 3) {
    if (grid[0][x] != grid[1][x] || grid[1][x] != grid[2][x]) {
      is_ok = false;
    }
  }

  cout << (is_ok ? "Yes" : "No") << el;
}
