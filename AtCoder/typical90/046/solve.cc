#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define el '\n'
#define rep(i,n) for (int i=0;i<(int)n;++i)
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

map<int, ll> gen_counter(const int& n) {
  map<int, ll> counter;
  rep(i, n) {
    int k;
    cin >> k;
    counter[k % 46]++;
  }
  return counter;
}

int main() {
  int n;
  cin >> n;

  auto amp = gen_counter(n);
  auto bmp = gen_counter(n);
  auto cmp = gen_counter(n);

  ll ans{};

  // {map.size}^3 <= 46^3
  for (auto const& [a, ac] : amp) {
    for (auto const& [b, bc] : bmp) {
      for (auto const& [c, cc] : cmp) {
        if ((a + b + c) % 46 == 0) {
          ans += ac * bc * cc;
        }
      }
    }
  }
  cout << ans << el;
}
