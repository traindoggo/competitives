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
using ld = long double;
// clang-format on

int main() {
  int n;
  cin >> n;
  vector<int> ai(n);

  vector<pair<ld, ld>> vp;
  rep(i, n) {
    ld a, b;
    cin >> a >> b;
    vp.emplace_back(a, b);
  }

  auto calc_time = [](ld a_cm, ld b_cm_per_sec) { return a_cm / b_cm_per_sec; };

  ld sum_time{};
  for (auto [a, b] : vp) {
    sum_time += calc_time(a, b);
  }

  ld collision_time = sum_time / 2;
  ld ans_cm{};

  for (auto [a, b] : vp) {
    ld t = calc_time(a, b);

    if (collision_time > t) {
      collision_time -= t;
      ans_cm += a;
    } else {
      ans_cm += collision_time * b;

      cout << fixed << setprecision(15);
      die(ans_cm);
    }
  }
}
