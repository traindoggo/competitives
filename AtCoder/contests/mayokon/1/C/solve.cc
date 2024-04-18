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
  int n;
  cin >> n;

  vector grid(n, vector<string>(n, "."));

  auto outbound = [&](int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
  };

  int idx{1};
  int y{}, x{}, d{0};  // direction

  while (idx < n * n) {
    grid[y][x] = to_string(idx);
    idx++;

    if (d == 0) {
      x++;
    } else if (d == 1) {
      y++;
    } else if (d == 2) {
      x--;
    } else {
      y--;
    }

    if (!outbound(y, x) || grid[y][x] != ".") {
      // back
      if (d == 0) {
        x--;
      } else if (d == 1) {
        y--;
      } else if (d == 2) {
        x++;
      } else {
        y++;
      }
      d = (d + 1) % 4;
      if (d == 0) {
        x++;
      } else if (d == 1) {
        y++;
      } else if (d == 2) {
        x--;
      } else {
        y--;
      }
    }
  }

  rep(h, n) {
    rep(w, n) {
      if (grid[h][w] == ".") {
        cout << "T ";
      } else {
        cout << grid[h][w] << (w == n - 1 ? '\n' : ' ');
      }
    }
  }
}
