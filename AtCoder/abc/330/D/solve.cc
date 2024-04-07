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

  vector<string> grid(n);
  rep(i, n) cin >> grid[i];

  vector<int> row(n, 0);
  vector<int> col(n, 0);

  rep(i, n) {
    int cnt{};
    rep(j, n) {
      if (grid[i][j] == 'o') cnt++;
    }
    row[i] = cnt;
  }

  rep(j, n) {
    int cnt{};
    rep(i, n) {
      if (grid[i][j] == 'o') cnt++;
    }
    col[j] = cnt;
  }

  llint cnt{};
  rep(i, n) {
    rep(j, n) {
      if (grid[i][j] == 'o') {
        cnt += (row[i] - 1) * (col[j] - 1);
      }
    }
  }
  cout << cnt << el;
}
