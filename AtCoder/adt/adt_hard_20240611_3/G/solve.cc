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

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> nums;
  rep(_, n) {
    int a, b;
    cin >> a >> b;
    rep(__, b) nums.push_back(a);
  }

  vector dp(3000, vector<bool>(18000, false));
  dp[0][0] = true;

  int size = (int)nums.size();
  dump(size);

  rep(i, size) {
    rep(j, x + 1) {
      // 支払えるんだったら更新
      if (dp[i][j]) {
        dp[i + 1][j] = true;
        dp[i + 1][j + nums[i]] = true;
      }
    }
  }

  if (dp[size][x])
    cout << "Yes" << el;
  else
    cout << "No" << el;
}
