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
  // n <= 10^3
  // q <= 10^3
  int n, q;
  cin >> n >> q;

  map<int, vector<int>> mp;
  rep(i, n) {
    int a;
    cin >> a;
    mp[a].push_back(i);
  }

  ll ans{};
  int idx{0};

  rep(_, q) {
    int b;
    cin >> b;

    // mp[b] の index
    int pos = lower_bound(all(mp[b]), idx) - mp[b].begin();
    if ((int)mp[b].size() == pos) pos--;

    int nx = mp[b][pos];
    ans += abs(idx - nx);
    idx = nx;
  }

  cout << ans << el;
}
