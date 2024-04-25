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

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;
// clang-format on

using vs = vector<string>;
using cvi = const vector<int>;

int count_color(vs grid, cvi &row, cvi &col) {
  int H = (int)grid.size();
  int W = (int)grid[0].size();

  // paint row
  for (auto r : row) {
    rep(w, W) grid[r][w] = '+';
  }

  // paint col
  for (auto c : col) {
    rep(h, H) grid[h][c] = '+';
  }

  int cnt{};
  rep(h, H) rep(w, W) if (grid[h][w] == '#') cnt++;
  return cnt;
}

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  vector<string> grid(h);
  rep(i, h) cin >> grid[i];

  int ans{};

  // choice row
  rep(rbit, 1 << h) {
    vector<int> row;
    rep(i, h) {
      if (rbit & (1 << i)) {
        row.push_back(i);
      }
    }

    // choice col
    rep(cbit, 1 << w) {
      vector<int> col;
      rep(i, w) {
        if (cbit & (1 << i)) {
          col.push_back(i);
        }
      }

      int cnt = count_color(grid, row, col);
      if (cnt == k) {
        ans++;
      }
    }
  }

  cout << ans << el;
}
