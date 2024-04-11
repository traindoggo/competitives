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

bool is_atcoder_char(char ch) {
  return ch == 'a' || ch == 't' || ch == 'c' || ch == 'o' || ch == 'd' ||
         ch == 'e' || ch == 'r';
}

int main() {
  string s, t;
  cin >> s >> t;

  vector<int> sa(26, 0), st(26, 0);
  int s_at{}, t_at{};

  for (auto ch : s) {
    if (ch == '@') {
      s_at++;
    } else {
      sa[(int)(ch - 'a')]++;
    }
  }

  for (auto ch : t) {
    if (ch == '@') {
      t_at++;
    } else {
      st[(int)(ch - 'a')]++;
    }
  }

  rep(i, 26) {
    char ch = (char)(i + 'a');

    if (sa[i] == st[i]) {
      // skip
    } else if (sa[i] > st[i]) {
      if (!is_atcoder_char(ch)) die("No");

      int diff = sa[i] - st[i];
      t_at -= diff;

    } else if (sa[i] < st[i]) {
      if (!is_atcoder_char(ch)) die("No");

      int diff = st[i] - sa[i];
      s_at -= diff;
    }
  }

  if (s_at == t_at && (s_at >= 0 && t_at >= 0))
    cout << "Yes" << el;
  else
    cout << "No" << el;
}
