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
using ull = unsigned long long int;

// clang-format on

int main() {
  string n;
  cin >> n;

  int k;
  cin >> k;

  auto conv = [](string str) -> string {
    // 8 to 10
    unsigned long long base10{};
    for (auto& ch : str) {
      base10 *= 8;
      base10 += (ull)(ch - '0');
    }

    // 10 to 9
    string ans{""};
    while (base10 > 0) {
      ans = (char)(base10 % 9 + '0') + ans;
      base10 /= 9;
    }
    for (char& ch : ans) {
      if (ch == '8') {
        ch = '5';
      }
    }

    return ans;
  };

  // n = 0;
  rep(_, k) n = conv(n);
  if (n == "")
    cout << 0 << el;
  else
    cout << n << el;
}
