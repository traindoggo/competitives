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

struct UnionFind {
  vector<int> par, rank;

  UnionFind(int n) : par(n), rank(n) {
    rep(i, n) {
      par[i] = i, rank[i] = 0;
    }
  }

  int root(int x) { return par[x] == x ? x : par[x] = root(par[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  void merge(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  }
};

using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<P> graph;

  rep(_, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph.push_back({a, b});
  }

  // greedy?
  int cnt{};
  UnionFind uf(n);
  for (auto [from, to] : graph) {
    if (uf.same(from, to)) {
      cnt++;
    } else {
      uf.merge(from, to);
    }
  }
  cout << cnt << el;
}
