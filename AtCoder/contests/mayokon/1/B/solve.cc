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
  string s, t;
  cin >> s >> t;

  // upper to lower
  string tt;
  for (auto ch : t) {
    tt.push_back((char)(ch - 'A' + 'a'));
  }

  dump(s, tt);

  int left{}, right{};

  while (left < (int)s.size() && right < (int)tt.size()) {
    if (s[left] == tt[right]) {
      left++, right++;
    } else {
      left++;
    }
  }

  if (right == 3) die("Yes");
  if (right == 2 && tt.back() == 'x') die("Yes");
  cout << "No" << el;
}
