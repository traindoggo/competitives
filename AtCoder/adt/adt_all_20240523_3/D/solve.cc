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
#define YesNo(f) cout<<(f?"Yes":"No")<<el

using ll = long long int;
// clang-format on

using Item = pair<int, bitset<200>>;

bool compare(const Item &pi, const Item &pj) {
  if (pi.first < pj.first) return false;

  rep(i, 100) {
    if (pi.second.test(i) == true && pj.second.test(i) == false) {
      return false;
    }
  }

  bool upper{false};
  rep(i, 100) {
    if (pi.second.test(i) == false && pj.second.test(i) == true) {
      upper = true;
    }
  }

  return pi.first > pj.first || upper == true;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Item> P(n);
  rep(i, n) {
    int p, c;
    cin >> p >> c;

    P[i].first = p;

    rep(_, c) {
      int f;
      cin >> f;
      P[i].second.set(f);
    }
  }

  bool has_compatible{false};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        if (compare(P[i], P[j])) {
          has_compatible = true;
        }
      }
    }
  }

  if (has_compatible)
    cout << "Yes" << el;
  else
    cout << "No" << el;
}
