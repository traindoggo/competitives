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

int main() {
  string s;
  cin >> s;

  auto is_capital = [](const char ch) { return 'A' <= ch && ch <= 'Z'; };

  int lower{}, upper{};
  for (auto& ch : s) {
    if (is_capital(ch)) {
      upper++;
    } else {
      lower++;
    }
  }

  string ans{};

  if (upper > lower) {
    // lower to upper
    for (auto& ch : s) {
      if (is_capital(ch)) {
        ans += ch;
      } else {
        ans += (char)(ch - 'a' + 'A');
      }
    }
  } else {
    for (auto& ch : s) {
      if (is_capital(ch)) {
        ans += (char)(ch - 'A' + 'a');
      } else {
        ans += ch;
      }
    }
  }

  cout << ans << el;
}
