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

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> grid(H);
  rep(i, H) cin >> grid[i];

  vector<vector<int>> dp(H, vector<int>(W, 0));
  dp[0][0] = 0;

  rep(h, H) {
    if (grid[h][0] == '.') {
      dp[h][0] = 1;
    } else {
      break;
    }
  }

  rep(w, W) {
    if (grid[0][w] == '.') {
      dp[0][w] = 1;
    } else {
      break;
    }
  }

  for (int h = 1; h < H; ++h) {
    for (int w = 1; w < W; ++w) {
      if (grid[h][w] == '.') {
        int cnt{};

        if (grid[h - 1][w] == '.') {
          cnt += dp[h - 1][w];
        }

        if (grid[h][w - 1] == '.') {
          cnt += dp[h][w - 1];
        }

        dp[h][w] = cnt % MOD17;
      }
    }
  }

  cout << dp[H - 1][W - 1] << el;
}
