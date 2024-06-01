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

namespace me {
int lower_bound(const vector<int>& ai, int key) {
  int left{-1}, right{(int)ai.size()};

  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (ai[mid] >= key) {
      right = mid;
    } else {
      left = mid;
    }
  }

  dump(left, right);
  return right;
}
}  // namespace me

int main() {
  int n;
  cin >> n;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];
  sort(all(ai));

  int q;
  cin >> q;
  rep(_, q) {
    int x;
    cin >> x;

    int idx = me::lower_bound(ai, x);
    cout << idx << el;
  }
}
