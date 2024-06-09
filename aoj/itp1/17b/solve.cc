#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/dump.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  FastIO{FastIO(){std::cin.tie(0);ios::sync_with_stdio(false);}} FastIO;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP0(n) for (auto i=0;i<n;++i)
#define REP1(i,n) for (auto i=std::decay_t<decltype(n)>{}; (i)!=(n); ++(i))
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

void solve(int n, int x) {
  int cnt{};

  rep(i, 1, n + 1) {
    rep(j, i + 1, n + 1) {
      rep(k, j + 1, n + 1) {
        if ((i + j + k) == x) {
          cnt++;
        }
      }
    }
  }

  cout << cnt << el;
}

int main() {
  int n, x;
  while (cin >> n >> x) {
    if (n == 0 && x == 0) break;
    solve(n, x);
  }
}
