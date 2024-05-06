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
  int n;
  cin >> n;

  if (n % 2 != 0) {
    cout << el;
    return 0;
  }

  string bracket{};
  rep(i, n / 2) bracket.push_back('(');
  rep(i, n / 2) bracket.push_back(')');

  auto is_good = [](const string& s) -> bool {
    int open{};
    for (auto ch : s) {
      if (ch == '(') {
        open++;
      } else {
        open--;
      }
      if (open < 0) return false;
    }
    return open == 0;
  };

  do {
    if (is_good(bracket)) {
      cout << bracket << el;
    }
  } while (next_permutation(all(bracket)));
}
