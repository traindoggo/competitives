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

using Graph = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n, vector<int>(n, 0));

  rep(_, m) {
    vector<int> ai(n);
    rep(i, n) cin >> ai[i], ai[i]--;

    rep(i, n - 1) {
      int left = ai[i];
      int right = ai[i + 1];

      graph[left][right] = 1;
      graph[right][left] = 1;
    }
  }

  rep(i, n) {
    dump(graph[i]);
  }

  int cnt{};
  rep(h, n) {
    rep(w, n) {
      if (h == w) continue;
      if (graph[h][w] == 0) cnt++;
    }
  }

  cout << cnt / 2 << el;
}
