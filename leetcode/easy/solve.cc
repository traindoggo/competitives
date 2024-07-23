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
  string longestCommonPrefix(vector<string>& strs) {
    size_t size{201};
    for (const string& s : strs) {
      size = min(size, s.size());
    }
    size_t length = strs.size();

    string ans{};

    rep(i, size) {
      bool is_same{true};
      char ch = strs[0][i];

      rep(j, length) {
        if (strs[j][i] != ch) {
          is_same = false;
        }
      }

      if (is_same) {
        ans.push_back(ch);
      } else {
        return ans;
      }
    }

    return ans;
  }
};

int main() {
  vector<pair<vector<string>, string>> vps{
      make_pair(vector<string>{"flower", "flow", "flight"}, "fl"),
      make_pair(vector<string>{"dog", "rececar", "car"}, ""),
      make_pair(vector<string>{"abcd", "abcd", "abcd"}, "abcd"),
      make_pair(vector<string>{"zebbra", "zebrin", "zeblan"}, "zeb"),
  };

  Solution sol;
  for (auto [strs, want] : vps) {
    string got = sol.longestCommonPrefix(strs);
    cout << "_ " << want << ' ' << got << el;
  }
}
