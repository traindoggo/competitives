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

int main() {
  int n;
  cin >> n;

  vector<vector<Edge>> edges(n);

  rep(_, n) {
    int u, k;
    cin >> u >> k;

    rep(__, k) {
      int vertex, cost;
      cin >> vertex >> cost;
      edges[u].push_back(Edge(vertex, cost));
    }
  }

  vector<int> costs(n, INFi);
  costs[0] = 0;

  // cost, to
  priority_queue<P, vector<P>, greater<P>> que;
  que.push({costs[0], 0});

  while (!que.empty()) {
    auto [from, cur_cost] = que.top();
    que.pop();

    if (costs[from] > cur_cost) continue;

    for (auto& edge : edges[from]) {
      const int nx_cost = costs[from] + edge.cost;

      if (nx_cost < costs[edge.to]) {
        costs[edge.to] = nx_cost;
        que.push({edge.to, nx_cost});
      }
    }
  }

  rep(i, n) {
    cout << i << ' ' << costs[i] << el;
  }
}
