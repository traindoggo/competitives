#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
#define el '\n'

#define all(k)  k.begin(),  k.end()
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

using P = pair<llint, llint>;

int main() {
  llint l, r;
  cin >> l >> r;

  vector<P> ans;

  // O(Log2 (2^60)) ?
  while (l < r) {
    llint new_l{};

    // MAX log2^60 = 60
    rep(k, 61) {
      llint left{l};
      llint r_now{};
      llint power2 = powl(2, k);

      // 2^i * j -> power2 ^ left * j
      if (left % power2 == 0) {
        llint j = left / power2;
        r_now = power2 * (j + 1);
      } else {
        r_now = left + 1;
      }

      if (r_now <= r) {
        chmax(new_l, r_now);
      }
    }

    ans.push_back({l, new_l});
    l = new_l;
  }

  sort(all(ans));
  cout << ans.size() << el;
  for (auto [l, r] : ans) {
    cout << l << ' ' << r << el;
  }
}
