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
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

using Graph = vector<vector<int>>;

int main() {
  int n, q;
  cin >> n >> q;

  Graph graph(n);

  rep(_, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<int> dist(n, -1);

  auto bfs = [&](int sv) {
    queue<int> que;
    que.push(sv);

    while (!que.empty()) {
      int v = que.front();
      que.pop();

      for (auto nv : graph[v]) {
        if (dist[nv] != -1) continue;
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  };

  // create dist map
  bfs(0);

  rep(_, q) {
    int c, d;
    cin >> c >> d;
    c--, d--;

    if (dist[c] % 2 == dist[d] % 2)
      cout << "Town" << el;
    else
      cout << "Road" << el;
  }
}
