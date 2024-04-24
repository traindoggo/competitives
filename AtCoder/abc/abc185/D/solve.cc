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

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

// alias
using ullint = unsigned long long int;
using llint  = long long int;
// clang-format on

int main() {
  int n, m;
  cin >> n >> m;

  if (m == 0) die(1);
  if (n == m) die(0);

  vector<int> ai(m, 0);
  rep(i, m) cin >> ai[i];
  ai.push_back(0);
  ai.push_back(n + 1);
  sort(ai.begin(), ai.end());

  int width{INFi};
  rep(i, m) chmin(width, ai[i + 1] - ai[i] - 1);
  if (width == 0) die(n - m);

  int cnt{};
  rep(i, m + 1) {
    int dist = ai[i + 1] - ai[i] - 1;
    cnt += (dist + width - 1) / width;
  }

  cout << cnt << el;
}
