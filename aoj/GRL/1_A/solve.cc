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

using P = pair<int, int>;

using Graph = vector<vector<Edge>>;

int main() {
  int v, e, r;
  cin >> v >> e >> r;

  // directed graph
  Graph graph(v);

  rep(_, e) {
    int s, t, d;
    cin >> s >> t >> d;
    graph[s].push_back(Edge(t, d));
  }

  // beginning at 'r'
  vector<int> cost(v, INFi);
  cost[r] = 0;

  // cost, to
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(make_pair(cost[r], r));

  while (!que.empty()) {
    auto [c, to] = que.top();
    que.pop();

    if (c > cost[to]) continue;

    for (auto& e : graph[to]) {
      if (chmin(cost[e.to], cost[to] + e.cost)) {
        que.push(make_pair(cost[e.to], e.to));
      }
    }
  }

  rep(i, v) {
    if (cost[i] == INFi)
      cout << "INF" << el;
    else
      cout << cost[i] << el;
  }
}
