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
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  p--, q--, r--, s--;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  vector<int> bi = ai;
  int size = q - p + 1;
  rep(i, size) bi[i + p] = ai[i + r];
  dump(bi);

  rep(i, size) bi[i + r] = ai[i + p];
  dump(bi);

  rep(i, n) {
    cout << bi[i] << (i == n - 1 ? el : ' ');
  }
}