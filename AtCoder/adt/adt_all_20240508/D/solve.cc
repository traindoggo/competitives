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

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> vs(n);
  rep(i, n) cin >> vs[i];

  int cnt{};

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int cur{};
      rep(k, m) {
        if (vs[i][k] == 'o' || vs[j][k] == 'o') {
          cur++;
        }
      }

      if (cur == m) {
        cnt++;
      }
    }
  }

  cout << cnt << el;
}
