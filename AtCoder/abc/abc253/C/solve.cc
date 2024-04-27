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
  int q;
  cin >> q;

  map<int, int, greater<>> mins;
  map<int, int, less<>> maxs;

  while (q--) {
    int op;
    cin >> op;

    if (op == 1) {
      int x;
      cin >> x;

      mins[x]++;
      maxs[x]++;
    } else if (op == 2) {
      int x, c;
      cin >> x >> c;

      if (mins[x] <= c) {
        mins.erase(x);
      } else {
        mins[x] -= c;
      }

      if (maxs[x] <= c) {
        maxs.erase(x);
      } else {
        maxs[x] -= c;
      }
    } else {
      auto n1 = maxs.begin();
      auto n2 = mins.begin();
      cout << n2->first - n1->first << el;
    }
  }
}
