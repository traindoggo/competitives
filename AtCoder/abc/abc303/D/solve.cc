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

using llint  = long long int;
// clang-format on

/*
 * s = AAAA
 *
 * (capslock押す ->) ボタンだけタイプ
 * - (z +) x * size(s) [ms]
 *
 * shift 押しながらボタンタイプ
 * - y * size(s) [ms]
 *
 * どれが小さいかを 'aaa...aa', 'AAa...AA'
 * の塊ごとに計算していくって感じ?
 * */

using P = pair<char, int>;

vector<P> compression(const string& s) {
  vector<P> tmp;

  string cur{};
  int prev{0};

  rep(i, (int)s.size()) {
    if (s[prev] == s[i]) {
      cur.push_back(s[prev]);
    } else {
      tmp.push_back({s[prev], i - prev});
      prev = i;
    }
  }

  return tmp;
}

int main() {
  llint x, y, z;
  cin >> x >> y >> z;

  string s;
  cin >> s;

  int n = (int)s.size();

  vector dp(n + 1, vector<llint>(2, INFll));
  dp[0][0] = 0;

  rep(i, n) {
    chmin(dp[i][0], dp[i][1] + z);
    chmin(dp[i][1], dp[i][0] + z);

    if (s[i] == 'a') {
      chmin(dp[i + 1][0], dp[i][0] + x);
      chmin(dp[i + 1][1], dp[i][1] + y);
    } else {
      chmin(dp[i + 1][0], dp[i][0] + y);
      chmin(dp[i + 1][1], dp[i][1] + x);
    }
  }

  cout << min(dp[n][0], dp[n][1]) << el;
}
