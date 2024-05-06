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

// Minimum Spanning Tree
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;

  Graph graph(n, vector<int>(n, INFi));
  rep(i, n) rep(j, n) {
    int k;
    cin >> k;
    if (k != -1) {
      graph[i][j] = k;
    }
  }

  // prim
  vector<int> dist(n, INFi), pi(n, -1), seen(n, 0);
  dist[0] = 0;

  while (true) {
    int minv = INFi;
    int u{-1};

    rep(i, n) {
      // 距離が最小のNode
      // 確定していない node
      if (minv > dist[i] && seen[i] != 2) {
        u = i;
        minv = dist[i];
      }
    }

    // 全頂点が決定
    if (u == -1) break;

    // あるノードを確定させる
    seen[u] = 2;

    rep(v, n) {
      // 確定していない and 連結しているノードの間
      if (seen[v] != 2 && graph[u][v] != INFi) {
        if (dist[v] > graph[u][v]) {
          dist[v] = graph[u][v];
          pi[v] = u;
          seen[u] = 1;
        }
      }
    }
  }

  int ans{};

  rep(i, n) {
    if (pi[i] != -1) {
      ans += graph[i][pi[i]];
    }
  }

  cout << ans << el;
}
