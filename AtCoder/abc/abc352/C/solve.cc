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

using P = pair<ll, ll>;

bool compare(const P& a, const P& b) {
  if (a.first > b.first) return true;
  if (a.second < b.second) return true;
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<P> giants;

  rep(i, n) {
    int a, b;
    cin >> a >> b;
    giants.push_back({a, b});
  }

  ll ans{}, cur{};

  // sum all shoulders
  rep(i, n) cur += giants[i].first;

  rep(i, n) {
    cur -= giants[i].first;
    cur += giants[i].second;
    chmax(ans, cur);

    cur -= giants[i].second;
    cur += giants[i].first;

    cout << ans << el;
  }
