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

struct Object {
  int hp;
  Object(int hp) : hp(hp) {}

  void damaged() { hp--; }
  bool dead() { return hp <= 0; }
};

int main() {
  int n, m, h, r;
  cin >> n >> m >> h >> r;

  // ai: enemy attack
  // bi: player defence
  vector<int> ai(n), bi(m);
  rep(i, n) cin >> ai[i];
  rep(i, m) cin >> bi[i];

  Object player(h), enemy(h);

  auto get_hit = [](int a, int r, int b) {
    /* dump(a - r, b, a); */
    return (max(0, a - r) <= b) && (b < a);
  };

  rep(i, n) {
    auto idx = lower_bound(bi.begin(), bi.end(), ai[i] - r);
    auto pos = distance(bi.begin(), idx);

    if (pos != m && get_hit(ai[i], r, bi[pos])) {
      enemy.damaged();
    } else {
      player.damaged();
    }

    if (player.dead()) die("Lose");
    if (enemy.dead()) die("Win");
  }

  cout << "Draw" << el;
}
