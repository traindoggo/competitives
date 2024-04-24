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
// clang-format on

using Graph = vector<vector<int>>;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  Graph graph(n);

  rep(_, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // btw, bfs
  vector<int> history;
  vector<bool> visited(n, false);
  bool is_goal{false};

  auto bfs = [&](auto f, int sv, const int &goal) {
    if (is_goal) return;
    history.push_back(sv);

    if (sv == goal) {
      is_goal = true;
      return;
    }

    visited[sv] = true;

    for (auto nv : graph[sv]) {
      if (visited[nv]) continue;
      f(f, nv, goal);
    }

    if (is_goal) return;
    history.pop_back();
  };

  x--, y--;
  bfs(bfs, x, y);

  int size = (int)history.size();
  rep(i, size) {
    cout << history[i] + 1 << (i == size - 1 ? '\n' : ' ');
  }
}
