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

struct Edge {
  int to;
  int cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};

using Graph = vector<vector<Edge>>;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  rep(_, m) {
    int a, b, cost;
    cin >> a >> b >> cost;
    a--, b--;

    graph[a].push_back(Edge(b, cost));
    graph[b].push_back(Edge(a, cost));
  }

  vector<int> cost(n, INFi);
  cost[0] = 0;

  priority_queue<P, vector<P>, greater<P>> que;

  // cost, to
  que.push(make_pair(cost[0], 0));

  while (!que.empty()) {
    // current cost, current vertex
    auto [c, v] = que.top();
    que.pop();

    if (c > cost[v]) continue;

    for (auto& edge : graph[v]) {
      if (chmin(cost[edge.to], cost[v] + edge.cost)) {
        que.push(make_pair(cost[edge.to], edge.to));
      }
    }
  }

  rep(i, n) {
    if (cost[i] == INFi)
      cout << -1 << el;
    else
      cout << cost[i] << el;
  }
}
