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
  int n, m;
  cin >> n >> m;

  Graph graph(n);
  rep(_, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  vector<bool> seen(n, false);
  auto dfs = [&](int sv) {
    seen[sv] = true;

    stack<int> st;
    st.push(sv);

    while (!st.empty()) {
      int v = st.top();
      st.pop();

      for (auto nv : graph[v]) {
        if (seen[nv]) continue;
        seen[nv] = true;
        st.push(nv);
      }
    }
  };

  dfs(0);

  rep(i, n) {
    if (!seen[i]) die("The graph is not connected.");
  }
  cout << "The graph is connected." << el;
}
