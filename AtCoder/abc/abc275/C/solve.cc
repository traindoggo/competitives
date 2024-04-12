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

const int N = 9;

using P = pair<int, int>;

int main() {
  vector<string> vs(N);
  rep(i, N) cin >> vs[i];

  set<P> ps;
  rep(y, N) rep(x, N) {
    if (vs[y][x] == '#') {
      ps.insert({y, x});
    }
  }

  // O(4 * logN)
  auto has_points = [&](const P& p0, const P& p1, const P& p2, const P& p3) {
    return ps.contains(p0) && ps.contains(p1) && ps.contains(p2) &&
           ps.contains(p3);
  };

  // O(1)
  auto manhattan = [](const P& p0, const P& p1) {
    return abs(p0.first - p1.first) + abs(p0.second - p1.second);
  };

  // O(1)
  auto is_square = [&](const P& p0, const P& p1, const P& p2, const P& p3) {
    int m0 = manhattan(p0, p1);
    int m1 = manhattan(p1, p2);
    int m2 = manhattan(p2, p3);
    int m3 = manhattan(p3, p0);
    return m0 == m1 && m1 == m2 && m2 == m3 && m3 == m0;
  };

  int cnt{};

  // O(N^4 * logN), N=9
  rep(y, N) rep(x, N) {
    for (int dy = 1; dy <= N; ++dy) {
      for (int dx = 1; dx <= N; ++dx) {
        // parallel
        {
          P p0 = {y, x};
          P p1 = {y, x + dx};
          P p2 = {y + dy, x + dx};
          P p3 = {y + dy, x};
          if (has_points(p0, p1, p2, p3) && is_square(p0, p1, p2, p3)) {
            cnt++;
          }
        }

        // diagonal
        {
          P p0 = {y, x};
          P p1 = {p0.first + dy, p0.second + dx};
          P p2 = {p1.first + dx, p1.second - dy};
          P p3 = {p2.first - dy, p2.second - dx};
          if (has_points(p0, p1, p2, p3) && is_square(p0, p1, p2, p3)) {
            cnt++;
          }
        }
      }
    }
  }

  cout << cnt << el;
}
