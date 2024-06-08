#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/dump.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define el '\n'
#define rep(i,n) for (int i=0;i<(int)n;++i)
#define die(msg) do{cout<<(msg)<<el;exit(0);}while(0);

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
  int n;
  cin >> n;

  Graph graph(n);

  rep(i, n) {
    int a;
    cin >> a;
    graph[i].push_back(a - 1);
  }

  // memorization
  map<int, ll> memo;

  auto dfs = [&](const int& sv) -> ll {
    vector<int> seen(n, false);
    seen[sv] = true;

    stack<int> st;
    st.push(sv);

    // sv itself
    ll cnt{1};

    while (!st.empty()) {
      int v = st.top();
      st.pop();
      // dump(v, memo);

      for (const int& nv : graph[v]) {
        if (memo.contains(nv)) {
          cerr << "cache" << el;
          return memo[sv] = cnt + memo[nv];
        }
        if (seen[nv]) continue;
        seen[nv] = true;
        st.push(nv);
        cnt++;
      }
    }

    return memo[sv] = cnt;
  };

  ll ans{};
  rep(i, n) {
    ll cnt = dfs(i);
    ans += cnt;
    dump(i, cnt, memo);
  }

  cout << ans << el;
}
