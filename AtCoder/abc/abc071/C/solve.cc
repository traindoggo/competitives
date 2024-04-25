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
  int n;
  cin >> n;

  map<llint, int> mp;
  rep(_, n) {
    llint a;
    cin >> a;
    mp[a]++;
  }

  llint rect1{}, rect2{};
  llint square{};

  for (auto [edge, cnt] : mp) {
    if (cnt >= 4) {
      chmax(square, edge);
    } else if (cnt >= 2) {
      if (rect1 < edge) {
        rect2 = rect1;
        chmax(rect1, edge);
      } else if (rect2 < edge && edge < rect1) {
        chmax(rect2, edge);
      }
    }
  }

  llint ans{};
  chmax(ans, square * square);
  chmax(ans, square * rect1);
  chmax(ans, square * rect2);
  chmax(ans, rect1 * rect2);
  cout << ans << el;
}
