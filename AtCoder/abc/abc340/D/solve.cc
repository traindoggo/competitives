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

using llint  = long long int;
// clang-format on

struct Edge {
  int to, cost;
  Edge() {}
  Edge(int to, int cost) : to(to), cost(cost) {}
};

// dist, vertex
using P = pair<llint, llint>;

int main() {
  int n;
  cin >> n;

  // Directed Weighted Graph
  vector<vector<Edge>> graph(n);
  rep(i, n - 1) {
    int a, b, x;
    cin >> a >> b >> x;
    x--;

    graph[i].push_back(Edge(i + 1, a));
    graph[i].push_back(Edge(x, b));
  }

  vector<llint> dist(n, INFll);
  dist[0] = 0;

  // Dijkstra
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, 0));

  while (!que.empty()) {
    auto [cur, v] = que.top();
    que.pop();

    // 同じ辺を見つけたらそれ以上見ない
    if (dist[v] != cur) continue;

    // ある頂点から出ている全部の辺を確認
    for (auto ne : graph[v]) {
      // 一つの辺を見る
      llint nd = cur + ne.cost;

      // 次のコストが、現在のコストより高いなら更新はしない
      if (nd >= dist[ne.to]) continue;

      // 最小コストを発見したら更新
      dist[ne.to] = nd;
      que.push(P(nd, ne.to));
    }
  }

  cout << dist[n - 1] << el;
}
