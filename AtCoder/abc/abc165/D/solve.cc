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
using llint  = long long int;
// clang-format on

int main() {
  llint a, b, n;
  cin >> a >> b >> n;

  auto f = [](llint a, llint x, llint b) {
    llint res1 = floor(a * x / b);
    llint res2 = a * floor(x / b);
    return res1 - res2;
  };

  llint ans{};
  if (b - 1 < n) {
    chmax(ans, f(a, b - 1, b));
  } else {
    chmax(ans, f(a, n, b));
  }
  cout << ans << el;
}
