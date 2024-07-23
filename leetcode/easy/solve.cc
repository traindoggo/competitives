#include <bits/stdc++.h>

#include <cassert>
#include <utility>
using namespace std;

#ifdef DEBUG_
#include <compe/dump.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  FastIO{FastIO(){std::cin.tie(0);ios::sync_with_stdio(false);}} FastIO;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP0(n)     for (auto i=0; i<n; ++i)
#define REP1(i,n)   for (auto i=std::decay_t<decltype(n)>{}; i!=n; ++i)
#define REP2(i,l,r) for (auto i=l; i<r; ++i)
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1, REP0)(__VA_ARGS__)

#define el '\n'
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

class Solution {
public:
  int romanToInt(string s) {
    map<char, int> mp{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                      {'C', 100}, {'D', 500}, {'M', 1000}};
    s = std::regex_replace(s, regex("CM"), "CCCCCCCCC");
    s = std::regex_replace(s, regex("CD"), "CCCC");
    s = std::regex_replace(s, regex("XC"), "XXXXXXXXX");
    s = std::regex_replace(s, regex("XL"), "XXXX");
    s = std::regex_replace(s, regex("IX"), "IIIIIIIII");
    s = std::regex_replace(s, regex("IV"), "IIII");

    int sum{};
    for (const char& ch : s) {
      sum += mp[ch];
    }
    cerr << s << ' ' << sum << el;
    return sum;
  };
};

int main() {
  vector<pair<string, int>> vps{
      make_pair("III", 3),
      make_pair("LVIII", 58),
      make_pair("MCDLXXVI", 1476),
      make_pair("MCMXCIV", 1994),
  };

  Solution sol;
  for (auto [s, n] : vps) {
    int got = sol.romanToInt(s);
    cout << got << ' ' << n << el;
  }
}
