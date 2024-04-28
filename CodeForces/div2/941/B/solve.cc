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
#define el '\n'
// clang-format on

using CVS = const vector<string>;

bool find_same_color_edge(CVS& grid, int n, int m, char color) {
  bool all_color{false};

  // top
  bool cur{true};
  rep(x, m) {
    if (grid[0][x] != color) cur = false;
  }
  if (cur) all_color = true;

  // bottom
  cur = true;
  rep(x, m) {
    if (grid[n - 1][x] != color) cur = false;
  }
  if (cur) all_color = true;

  // left
  cur = true;
  rep(y, n) {
    if (grid[y][0] != color) cur = false;
  }
  if (cur) all_color = true;

  // right
  cur = true;
  rep(y, n) {
    if (grid[y][m - 1] != color) cur = false;
  }
  if (cur) all_color = true;

  return all_color;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  rep(i, n) cin >> grid[i];

  bool all_black = find_same_color_edge(grid, n, m, 'B');
  bool all_white = find_same_color_edge(grid, n, m, 'W');

  cout << (all_black && all_white ? "NO" : "YES") << el;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
