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

namespace me {
int lower_bound(const vector<ll>& ai, ll key) {
  int ng{-1}, ok{(int)ai.size()};
  while (ok - ng > 1) {
    int mid = ng + (ok - ng) / 2;
    if (key < ai[mid]) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int upper_bound(const vector<ll>& ai, ll key) {
  int left{-1}, right{(int)ai.size()};

  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (key > ai[mid]) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return right;
}
}  // namespace me

int main() {
  ll n;
  cin >> n;

  vector<ll> ai(n), bi(n), ci(n);
  rep(i, n) cin >> ai[i];
  rep(i, n) cin >> bi[i];
  rep(i, n) cin >> ci[i];

  sort(all(ai));
  sort(all(bi));
  sort(all(ci));

  ll ans{};
  for (const ll& b : bi) {
    ll a = me::upper_bound(ai, b);
    ll c = me::lower_bound(ci, b);

    ans += a * (n - c);
  }
  cout << ans << el;
}
