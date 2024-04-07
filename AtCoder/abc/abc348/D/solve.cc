#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

using VS = vector<string>;
using VVI = vector<vector<int>>;
using VVB = vector<vector<bool>>;

int dy[]{0, -1, 1, 0};
int dx[]{-1, 0, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  int n;
  cin >> n;

  VVI meds(h, vector<int>(w, -1));
  rep(_, n) {
    int r, c, e;
    cin >> r >> c >> e;
    r--, c--;
    meds[r][c] = e;
  }

  int sy{}, sx{};
  rep(i, h) rep(j, w) {
    if (grid[i][j] == 'S') sy = i, sx = j;
  }
}
