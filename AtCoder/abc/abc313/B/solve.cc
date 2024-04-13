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

  Graph graph(n);

  rep(_, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
  }

  auto dfs = [&](int sv) -> int {
    queue<int> que;
    que.push(sv);

    set<int> visited;
    visited.insert(sv);

    while (!que.empty()) {
      int v = que.front();
      que.pop();

      for (auto nv : graph[v]) {
        if (visited.find(nv) != visited.end()) continue;
        visited.insert(nv);
        que.push(nv);
      }
    }

    if ((int)visited.size() == n) {
      return sv + 1;
    } else {
      return -1;
    }
  };

  rep(player, n) {
    int saikyo = dfs(player);
    if (saikyo != -1) die(saikyo);
  }

  cout << -1 << el;
}
