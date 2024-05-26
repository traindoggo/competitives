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
#define die(msg) cout<<(msg)<<el;exit(0);

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

namespace me {
int upper_bound(const vector<int>& ai, int key) {
  int left{}, right{(int)ai.size()};

  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (key >= ai[mid]) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return right;
}
}  // namespace me

/*
 *     +-------+
 * +---|---+   |
 * |   |   |   |
 *
 * +--------+
 * | +----+ |
 * | |    | |
 *
 * +-----+  +-----+
 * |     |  |     |
 * */

int main() {
  ll n;
  cin >> n;

  vector<P> vp;
  vector<int> li(n);
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    vp.push_back({l, r});
    li[i] = l;
  }

  sort(all(vp));
  sort(all(li));

  ll ans{};

  rep(i, n) {
    int l = vp[i].second;
    int idx = me::upper_bound(li, l);
    ans += idx - i - 1;
  }

  cout << ans << el;
}
