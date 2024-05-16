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

using Graph = vector<int>;

int main() {
  int n;
  cin >> n;

  Graph graph(n);
  rep(i, n) cin >> graph[i], graph[i]--;

  // 閉路は必ず存在する
  int idx{};
  {
    int v = 0;
    set<int> st;
    while (true) {
      if (st.contains(v)) break;
      st.insert(v);
      v = graph[v];
    }
    idx = v;  // found closed cycle :^)
  }

  // なんだこの実装
  // 絶対一回目のループで上手に解ける
  dump(idx);
  vector<int> ans;
  set<int> st;
  while (true) {
    if (st.contains(idx)) break;
    st.insert(idx);
    ans.push_back(idx);
    idx = graph[idx];
  }

  dump(ans);
  int size = (int)ans.size();
  cout << size << el;
  rep(i, size) {
    cout << ans[i] + 1 << (i != size - 1 ? ' ' : '\n');
  }
}
