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
#define die(msg) cout<<(msg)<<el;exit(0);

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

using Graph = vector<vector<int>>;

int main() {
  int n, t;
  cin >> n >> t;

  vector<int> ai(t);
  rep(i, t) cin >> ai[i], ai[i]--;

  vector<int> rows(2 * n, 0), cols(2 * n, 0);
  // 左上から右下, 左下から右上
  ll diag1{0}, diag2{0};

  rep(tt, t) {
    int a = ai[tt];
    int row = a / n;
    int col = a % n;

    if (row == col) {
      diag1++;
    }

    if (row + col == n - 1) {
      diag2++;
    }

    rows[row]++;
    cols[col]++;

    if (diag1 >= n) {
      die(tt + 1);
    } else if (diag2 >= n) {
      die(tt + 1);
    } else if (rows[row] >= n) {
      die(tt + 1);
    } else if (cols[col] >= n) {
      die(tt + 1);
    }
  }

  cout << -1 << el;
}
