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
  int a, b;
  cin >> a >> b;

  vector grid(b, vector<llint>(a, 0));

  int n;
  cin >> n;
  rep(_, n) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    grid[y][x] = -1;
  }

  // init
  grid[0][0] = 1;

  for (int y = 1; y < b; ++y) {
    if (grid[y][0] != -1) {
      grid[y][0] = grid[y - 1][0];
    }
  }

  for (int x = 1; x < a; ++x) {
    if (grid[0][x] != -1) {
      grid[0][x] = grid[0][x - 1];
    }
  }

  for (int y = 1; y < b; ++y) {
    for (int x = 1; x < a; ++x) {
      if (grid[y][x] == -1) continue;
      llint top = grid[y - 1][x];
      llint left = grid[y][x - 1];

      if (top != -1) grid[y][x] += top;
      if (left != -1) grid[y][x] += left;
    }
  }

  cout << grid[b - 1][a - 1] << el;
}
