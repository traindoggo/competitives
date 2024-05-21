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

using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  vector<int> ys;
  vector<P> vs;
  rep(_, n) {
    int x, y;
    cin >> x >> y;
    vs.push_back({x, y});
    ys.push_back(y);
  }

  string s;
  cin >> s;

  // init
  // o ->      <- o
  map<int, int> go_right, go_left;
  rep(i, n) {
    char direction = s[i];
    int y = ys[i];
    if (direction == 'R') {
      go_right[y] = INFi;
    } else {
      go_left[y] = -1;
    }
  }

  rep(i, n) {
    char direction = s[i];
    auto [x, y] = vs[i];
    if (direction == 'R') {
      // most smallest pos
      chmin(go_right[y], x);
    } else {
      // most largest pos
      chmax(go_left[y], x);
    }
  }

  bool is_collision{false};
  for (auto y : ys) {
    if (go_right.contains(y) && go_left.contains(y)) {
      // collision!
      // o ->   <- o
      if (go_right[y] < go_left[y]) {
        is_collision = true;
      }
    }
  }

  if (is_collision)
    cout << "Yes" << el;
  else
    cout << "No" << el;
}
