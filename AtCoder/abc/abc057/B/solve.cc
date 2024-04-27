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

using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<P> students, checkpoints;
  rep(_, n) {
    int a, b;
    cin >> a >> b;
    students.push_back({a, b});
  }

  rep(_, m) {
    int c, d;
    cin >> c >> d;
    checkpoints.push_back({c, d});
  }

  auto dist = [](int x1, int y1, int x2, int y2) -> int {
    return abs(x1 - x2) + abs(y1 - y2);
  };

  rep(i, n) {
    int cur{INFi};
    int ans{};
    auto s = students[i];

    rep(j, m) {
      auto p = checkpoints[j];
      int d = dist(s.first, s.second, p.first, p.second);
      if (chmin(cur, d)) {
        ans = j + 1;
      }
    }

    // ans
    cout << ans << el;
  }
}
