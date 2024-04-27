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

/*
 * directed graph
 *
 * dfs/bfs で全長点から行ける場所全部をカウント
 * その値がそのまま答え
 * */

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
    stack<int> st;
    st.push(sv);

    vector<bool> visited(n, false);
    visited[sv] = true;

    while (!st.empty()) {
      int v = st.top();
      st.pop();

      for (auto nv : graph[v]) {
        if (visited[nv]) continue;
        visited[nv] = true;
        st.push(nv);
      }
    }

    int cnt{};
    for (auto v : visited) {
      if (v) cnt++;
    }
    return cnt;
  };

  int cnt{};
  rep(i, n) {
    cnt += dfs(i);
  }
  cout << cnt << el;
}
