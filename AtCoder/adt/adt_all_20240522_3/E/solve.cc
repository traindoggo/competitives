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

using Graph = vector<vector<int>>;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  Graph graph(n);
  rep(_, n - 1) {
    int from, to;
    cin >> from >> to;
    from--, to--;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  vector<int> path, trace;
  path.push_back(x - 1);
  vector<bool> seen(n, false);

  auto dfs = [&](auto f, int sv) {
    seen[sv] = true;

    if (sv == y - 1) {
      trace = path;
      return;
    }

    for (auto& nv : graph[sv]) {
      if (seen[nv]) continue;
      path.push_back(nv);
      f(f, nv);
      path.pop_back();
    }
  };

  dfs(dfs, x - 1);

  dump(path);
  dump(trace);

  int size = (int)trace.size();
  rep(i, size) {
    cout << trace[i] + 1 << (i != size - 1 ? ' ' : '\n');
  }
}
