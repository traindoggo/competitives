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

using ll = long long int;
// clang-format on

using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;

  rep(i, n) {
    vector<int> row;
    rep(j, n) {
      int a;
      cin >> a;
      if (a == 1) {
        row.push_back(j + 1);
      }
    }

    int size = (int)row.size();
    rep(j, size) {
      cout << row[j] << (j != size - 1 ? ' ' : '\n');
    }
  }
}
