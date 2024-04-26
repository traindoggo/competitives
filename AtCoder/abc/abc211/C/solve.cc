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
// clang-format on

int main() {
  string s;
  cin >> s;

  int n = (int)s.size();
  string chokudai{"chokudai"};

  vector dp(n + 1, vector<int>(9, 0));
  rep(i, n + 1) dp[i][0] = 1;

  rep(i, n) rep(j, 8) {
    if (s[i] != chokudai[j]) {
      dp[i + 1][j + 1] = dp[i][j + 1];
    } else {
      dp[i + 1][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD17;
    }
  }

  cout << dp[n][8] << el;
}
