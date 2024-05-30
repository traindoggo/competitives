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

vector<vector<int>> input(int h, int w) {
  vector<vector<int>> tmp(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> tmp[i][j];
  return tmp;
}

int main() {
  int h1, w1;
  cin >> h1 >> w1;
  auto matA = input(h1, w1);

  int h2, w2;
  cin >> h2 >> w2;
  auto matB = input(h2, w2);

  rep(bit, 1 << h1) {
    vector<vector<int>> rows;
    rep(i, h1) {
      if (bit & (1 << i)) {
        rows.push_back(matA[i]);
      }
    }

    rep(bit1, 1 << w1) {
      vector<vector<int>> grid;
      rep(h, (int)rows.size()) {
        vector<int> row;
        rep(j, w1) {
          if (bit1 & (1 << j)) {
            row.push_back(rows[h][j]);
          }
        }

        grid.push_back(row);
      }

      // rep(a, (int)grid.size()) dump(grid[a]);

      if (grid == matB) die("Yes");
    }
  }

  cout << "No" << el;
}
