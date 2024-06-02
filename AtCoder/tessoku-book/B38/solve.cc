#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/dump.hpp>
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
// clang-format on

/*
 * AAABBB
 *
 * 123...
 *    421
 *
 * AAABBBA
 * 123
 * ...432.
 * ......1
 *
 * [AAAAA][BBB][A...]
 *  12345  654  12..
 *  12345  632  12..
 * */
int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> ahi(n, 1), bhi(n, 1);

  rep(i, n) {
    if (s[i] == 'A') {
      ahi[i + 1] = ahi[i] + 1;
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'B') {
      bhi[i] = bhi[i + 1] + 1;
    }
  }

  dump(ahi);
  dump(bhi);

  int ans{};
  rep(i, n) ans += max(ahi[i], bhi[i]);
  cout << ans << el;
}
