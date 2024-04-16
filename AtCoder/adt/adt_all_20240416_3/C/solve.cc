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

using vs = vector<string>;

bool check(vs ai, vs bi, int s, int t) {
  int h = (int)ai.size();
  int w = (int)ai.front().size();

  // vertical
  rep(_, s) {
    rep(j, w) rep(i, h - 1) {
      swap(ai[i][j], ai[(i + 1) % h][j]);
    }
  }

  // horizontal shift
  rep(_, t) {
    rep(i, h) rep(j, w - 1) {
      swap(ai[i][j], ai[i][(j + 1) % w]);
    }
  }

  bool is_same{true};
  rep(i, h) rep(j, w) {
    if (ai[i][j] != bi[i][j]) {
      is_same = false;
    }
  }

  return is_same;
}

int main() {
  int h, w;
  cin >> h >> w;

  vs ai(h), bi(h);
  rep(i, h) cin >> ai[i];
  rep(i, h) cin >> bi[i];

  for (int i = 0; i <= h; ++i) {
    for (int j = 0; j <= w; ++j) {
      if (check(ai, bi, i, j)) {
        die("Yes");
      }
    }
  }

  cout << "No" << el;
}
