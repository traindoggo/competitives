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

vector<bool> create_eratosthenes(int n) {
  vector<bool> sheet(n + 1, true);

  sheet[0] = false;
  sheet[1] = false;

  for (int p = 2; p <= n; ++p) {
    if (!sheet[p]) continue;

    for (int q = p * 2; q <= n; q += p) {
      sheet[q] = false;
    }
  }

  return sheet;
}

int main() {
  int q;
  cin >> q;

  vector<int> xi(q);
  rep(i, q) cin >> xi[i];

  vector<bool> primes = create_eratosthenes(300001);

  for (const int& x : xi) {
    if (primes[x])
      cout << "Yes" << el;
    else
      cout << "No" << el;
  }
}
