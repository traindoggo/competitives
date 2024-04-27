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

using llint  = long long int;
// clang-format on

int main() {
  llint n, d, p;
  cin >> n >> d >> p;

  vector<llint> fi(n);
  rep(i, n) cin >> fi[i];
  sort(fi.rbegin(), fi.rend());

  vector<llint> acc(n + 1);
  rep(i, n) acc[i + 1] = acc[i] + fi[i];

  llint sum{};
  for (int i = 0; i < (n + d - 1) / d; ++i) {
    llint diff;

    // outbound
    if ((i + 1) * d >= n) {
      diff = acc[n] - acc[i * d];
    } else {
      diff = acc[(i + 1) * d] - acc[i * d];
    }

    if (diff > p) {
      sum += p;
    } else {
      sum += diff;
    }
  }
  cout << sum << el;
}
