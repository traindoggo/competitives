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
  int to, cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};

using Graph = vector<vector<Edge>>;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  Graph graph(n);

  rep(_, n) {
    int u, k;
    cin >> u >> k;

    rep(__, k) {
      int to, cost;
      cin >> to >> cost;
      graph[u].push_back(Edge(to, cost));
    }
  }

  vector<int> dist(n, INFi);

  auto dijkstra = [&](int sv) {
    dist[sv] = 0;

    // <to, cost>
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({sv, 0});

    while (!pq.empty()) {
      auto [from, cost] = pq.top();
      pq.pop();

      if (dist[from] < cost) continue;

      for (auto [nto, ncost] : graph[from]) {
        const int d = dist[from] + ncost;

        if (d < dist[nto]) {
          dist[nto] = d;
          pq.push({nto, d});
        }
      }
    }
  };

  dijkstra(0);

  rep(i, n) {
    cout << i << ' ' << dist[i] << el;
  }
}
