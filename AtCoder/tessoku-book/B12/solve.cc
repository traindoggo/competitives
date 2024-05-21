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
using ld = long double;
// clang-format on

ld f(ld x) {
  return x * x * x + x;
}

int main() {
  ld n;
  cin >> n;

  ld left{}, right{1e16};

  while (0.000001 < right - left) {
    ld mid = left + (right - left) / 2;

    if (n <= f(mid)) {
      right = mid;
    } else {
      left = mid;
    }
    dump(left, right);
  }

  cout << fixed << setprecision(8);
  cout << right << el;
}
