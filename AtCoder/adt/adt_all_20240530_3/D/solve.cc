#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
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
using ld = long double;
// clang-format on

int main() {
  /*
   * (X, Y) = (cos0 sin0) (x)
   *          (sin0 cos0) (y)
   *
   *
   * X = cos0 * x - sin0 * y
   * Y = sin0 * x + cos0 * y
   * */
  ld a, b, d;
  cin >> a >> b >> d;
  ld rad = d * (M_PI / 180.0);

  ld X = cos(rad) * a - sin(rad) * b;
  ld Y = sin(rad) * a + cos(rad) * b;

  cout << fixed << setprecision(20);
  cout << X << ' ' << Y << el;
}
