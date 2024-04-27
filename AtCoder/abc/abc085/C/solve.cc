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
  llint N, Y;
  cin >> N >> Y;

  for (llint x = 0; x <= N; ++x) {
    for (llint y = 0; y <= N; ++y) {
      llint sum = 10000 * x + 5000 * y;
      llint z = (Y - sum) / 1000;

      if (0 <= z && z == (N - x - y) &&
          (Y == 10000 * x + 5000 * y + 1000 * z)) {
        cout << x << ' ' << y << ' ' << z << el;
        return 0;
      }
    }
  }

  cout << -1 << ' ' << -1 << ' ' << -1 << el;
}
