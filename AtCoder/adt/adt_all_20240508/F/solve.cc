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

  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  int y{}, x{};
  int dist{};
  set<pair<int, int>> pos;

  while (true) {
    // outbound -> then stop moving
    if (!(0 <= y && y < h && 0 <= x && x < w)) {
      // prev move
      if (dist == 0) {
        y++;
      } else if (dist == 1) {
        y--;
      } else if (dist == 2) {
        x++;
      } else if (dist == 3) {
        x--;
      }

      // 1-index move !!!
      cout << y + 1 << ' ' << x + 1 << el;
      return 0;
    }

    //  eternaly moving :^)
    if (pos.contains({y, x})) {
      die("-1");
    }

    pos.insert({y, x});

    char mv = grid[y][x];
    if (mv == 'U') {
      dist = 0;
    } else if (mv == 'D') {
      dist = 1;
    } else if (mv == 'L') {
      dist = 2;
    } else if (mv == 'R') {
      dist = 3;
    }

    if (dist == 0) {
      y--;
    } else if (dist == 1) {
      y++;
    } else if (dist == 2) {
      x--;
    } else if (dist == 3) {
      x++;
    }
  }
}
