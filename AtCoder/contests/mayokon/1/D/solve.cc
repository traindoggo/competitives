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

int main() {
  llint n, k;
  cin >> n >> k;

  // 0 ... n | 1
  // 0 ... n | 2
  // ...
  // 0 ... n | k
  //
  // 0 1 2 ... k * n

  llint alls{};

  // rep(_, n - k + 1) {
  for (llint i = k; i <= n + 1; ++i) {
    llint mins = i * (i - 1) / 2;
    llint maxs = (2 * n - i + 1) * i / 2;
    llint cnt = maxs - mins + 1;
    alls = (alls + cnt) % MOD17;
  }

  cout << alls << el;
}
