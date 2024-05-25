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

  vector<int> ai(n - 1), bi(n - 2);
  rep(i, n - 1) cin >> ai[i];
  rep(i, n - 2) cin >> bi[i];

  vector<int> dp(n + 1, INFi);
  dp[0] = 0;

  rep(i, n) {
    if (i < n - 1) {
      chmin(dp[i + 1], dp[i] + ai[i]);
    }
    if (i < n - 2) {
      chmin(dp[i + 2], dp[i] + bi[i]);
    }
  }

  dump(ai);
  dump(bi);
  dump(dp);

  vector<int> history;
  int place{n - 1};

  while (true) {
    history.push_back(place + 1);
    if (place == 0) break;

    if (dp[place - 1] + ai[place - 1] == dp[place])
      place -= 1;
    else
      place -= 2;
  }

  reverse(all(history));

  int size = (int)history.size();
  cout << size << el;
  rep(i, size) {
    if (i > 0) cout << ' ';
    cout << history[i];
  }
  cout << el;
}
