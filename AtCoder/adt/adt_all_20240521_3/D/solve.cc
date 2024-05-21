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

  // n <= 10^5
  rep(i, n) {
    // どうせ小さい
    sort(all(graph[i]));

    int size = (int)graph[i].size();
    if (size != 0) {
      cout << size << ' ';
      rep(j, size) {
        cout << graph[i][j] + 1;
        if (j < size - 1) cout << ' ';
      }
      cout << el;
    } else {
      cout << size << el;
    }
  }
}
