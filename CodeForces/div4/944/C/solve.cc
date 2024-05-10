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

struct P {
  int a, b;
};

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  P alice{min(a, b), max(a, b)};
  P bob{min(c, d), max(c, d)};

  if (alice.a < bob.a && bob.a < alice.b && alice.b < bob.b) {
    cout << "YES" << el;
    return;
  }

  if (bob.a < alice.a && alice.a < bob.b && bob.b < alice.b) {
    cout << "YES" << el;
    return;
  }

  cout << "NO" << el;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
