#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

set<llint> divs(llint a) {
  set<llint> res;
  for (int i = 2; i * i <= a; ++i) {
    while (a % i == 0) {
      res.insert(i);
      res.insert(a / i);
      a /= i;
    }
  }
  return res;
}

int main() {
  llint n, m, k;
  cin >> n >> m >> k;

  llint d = lcm(n, m);
  llint left{0}, right{1LL << 61};

  while (right - left > 1) {
    llint mid = left + (right - left) / 2;
    llint num = mid / n + mid / m - 2 * (mid / d);

    if (num < k) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << right << el;
}
