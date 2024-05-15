#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0;i<(int)n;++i)
#define die(msg) do{cout<<(msg)<<'\n',exit(0);}while(0)
#define el '\n'

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

  // A B C
  // A B A B
  // A B A B C
  // A B [A B C]
  // A B - C
  // [A B C]
  vector<char> vs;

  // |S| <= 2 * 10^5
  for (auto ch : s) {
    if (vs.size() >= 2) {
      if (ch == 'C') {
        int size = (int)vs.size();
        if (vs[size - 2] == 'A' && vs[size - 1] == 'B') {
          vs.pop_back();  // O(1)
          vs.pop_back();  // O(1)
        } else {
          vs.push_back(ch);  // O(1)
        }
      } else {
        vs.push_back(ch);
      }
    } else {
      vs.push_back(ch);
    }
  }

  for (auto ch : vs) {
    cout << ch;
  }
  cout << el;
}
