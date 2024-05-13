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

// to, cost
using P = pair<int, int>;

bool compare(const Edge& a, const Edge& b) {
  return a.cost < b.cost;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<P>> graph(n);
  rep(_, m) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from--, to--;

    graph[from].push_back(make_pair(to, cost));
    graph[to].push_back(make_pair(from, cost));
  }

  vector<bool> seen(n, false);
  vector<int> costs(n, INFi);
  priority_queue<P, vector<P>, greater<P>> que;

  costs[0] = 0;

  // cost, to
  que.push(make_pair(costs[0], 0));

  while (!que.empty()) {
    auto [_, cur] = que.top();
    que.pop();

    if (seen[cur]) continue;
    seen[cur] = true;

    rep(i, (int)graph[cur].size()) {
      int nx = graph[cur][i].first;
      int nx_cost = graph[cur][i].second;

      if (costs[nx] > costs[cur] + nx_cost) {
        costs[nx] = costs[cur] + nx_cost;
        que.push(make_pair(costs[nx], nx));
      }
    }
  }

  rep(i, n) {
    if (costs[i] == INFi) {
      cout << -1 << el;
    } else {
      cout << costs[i] << el;
    }
  }
}
