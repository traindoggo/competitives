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

// const
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

// alias
using ullint = unsigned long long int;
using llint  = long long int;
// clang-format on

int main() {
  int n;
  cin >> n;

  vector<llint> qi(n), ai(n), bi(n);
  rep(i, n) cin >> qi[i];
  rep(i, n) cin >> ai[i];
  rep(i, n) cin >> bi[i];

  /*
   * k * A1 + t * B1 <= Q1
   * k * A2 + t * B2 <= Q2
   * ...
   * k * An + t * Bn <= Qn
   * */
  llint ans{};
  llint maxq = *max_element(qi.begin(), qi.end());

  for (int k = 0; k <= maxq; ++k) {
    llint t{INFll};

    rep(i, n) {
      if (qi[i] < ai[i] * k) {
        t = -INFll;
      } else if (bi[i] > 0) {
        chmin(t, (qi[i] - ai[i] * k) / bi[i]);
      }
    }
    chmax(ans, k + t);
  }

  cout << ans << el;
}
