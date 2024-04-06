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

tuple<string, string> conv(int hh, int mm) {
  string h{}, m{};
  if (hh < 10)
    h = "0" + to_string(hh);
  else
    h = to_string(hh);

  if (mm == 0)
    m = "00";
  else if (mm < 10)
    m = "0" + to_string(mm);
  else
    m = to_string(mm);

  return {h, m};
}

int main() {
  int n;
  cin >> n;

  rep(_, n) {
    string s;
    cin >> s;

    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3));

    if (hh == 0) {
      auto [h, m] = conv(hh, mm);
      cout << "12:" << m << " AM" << el;
    } else if (hh == 12) {
      auto [h, m] = conv(hh, mm);
      cout << "12:" << m << " PM" << el;
    } else if (hh >= 12) {
      auto [h, m] = conv(hh - 12, mm);
      cout << h << ":" << m << " PM" << el;
    } else {
      auto [h, m] = conv(hh, mm);
      cout << h << ":" << m << " AM" << el;
    }
  }
}
