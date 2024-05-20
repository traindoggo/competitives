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
  int h, w;
  cin >> h >> w;

  vector<vector<int>> grid(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> grid[i][j];

  vector<int> row(h, 0), col(w, 0);
  rep(i, h) {
    int sum{};
    rep(j, w) sum += grid[i][j];
    row[i] = sum;
  }

  rep(j, w) {
    int sum{};
    rep(i, h) sum += grid[i][j];
    col[j] = sum;
  }

  rep(i, h) {
    rep(j, w) {
      cout << row[i] + col[j] - grid[i][j] << (j != w - 1 ? ' ' : '\n');
    }
  }
}
