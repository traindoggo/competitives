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

using llint  = long long int;
// clang-format on

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> vs(n);
  rep(i, n) cin >> vs[i];
  sort(all(vs));

  // O(N!), N <= 8
  do {
    bool is_ok{true};

    // O(NM)
    rep(i, n - 1) {
      int cnt{};
      rep(j, m) {
        if (vs[i][j] != vs[i + 1][j]) {
          cnt++;
        }
      }
      if (cnt != 1) is_ok = false;
    }

    if (is_ok) die("Yes");
  } while (next_permutation(all(vs)));

  cout << "No" << el;
}
