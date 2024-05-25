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

using P = pair<pair<int, int>, int>;

int main() {
  int H, W, n;
  cin >> H >> W >> n;

  vector<int> ys, xs;

  rep(i, n) {
    int y, x;
    cin >> y >> x;

    ys.push_back(y);
    xs.push_back(x);
  }

  auto conv = [](const vector<int> ai) -> map<int, int> {
    map<int, int> mp;
    set<int> st{ai.begin(), ai.end()};
    int idx{1};
    for (auto a : st) {
      mp[a] = idx++;
    }
    return mp;
  };

  map<int, int> yy = conv(ys), xx = conv(xs);

  rep(i, n) {
    cout << yy[ys[i]] << ' ' << xx[xs[i]] << el;
  }
}
