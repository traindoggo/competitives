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

  vector<string> ci(n), di(m);
  rep(i, n) cin >> ci[i];
  rep(i, m) cin >> di[i];

  vector<int> pi(m + 1);
  rep(i, m + 1) cin >> pi[i];

  map<string, int> mp;
  rep(i, m) mp[di[i]] = pi[i + 1];

  int ans{};
  rep(i, n) {
    string name = ci[i];
    if (mp.contains(name)) {
      ans += mp[name];
    } else {
      ans += pi[0];
    }
  }
  cout << ans << el;
}
