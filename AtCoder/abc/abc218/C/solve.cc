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

vector<string> shrink(const vector<string>& grid, const int& n) {
  int top{INFi}, left{INFi}, bottom{}, right{};

  rep(i, n) rep(j, n) {
    if (grid[i][j] == '#') {
      chmin(top, i);
      chmin(left, j);
      chmax(bottom, i);
      chmax(right, j);
    }
  }

  vector<string> tmp;
  for (int y = top; y <= bottom; ++y) {
    string row = grid[y].substr(left, right - left + 1);
    tmp.push_back(row);
  }

  return tmp;
}

int main() {
  int n;
  cin >> n;

  vector<string> si(n), ti(n);
  rep(i, n) cin >> si[i];
  rep(i, n) cin >> ti[i];

  auto rotate = [](vector<string> k) -> vector<string> {
    int h = (int)k.size();
    int w = (int)k[0].size();

    // convert 90 degrees
    vector<string> tmp(w);
    rep(x, w) rep(y, h) tmp[x] += k[h - y - 1][x];
    return tmp;
  };

  vector<string> ssi = shrink(si, n);
  vector<string> origin = shrink(ti, n);

  rep(idx, 5) {
    // rotate
    ssi = rotate(ssi);

    if (ssi.size() != origin.size() || ssi[0].size() != origin[0].size()) {
      continue;
    }

    if (ssi == origin) {
      die("Yes");
    }
  }

  cout << "No" << el;
}
