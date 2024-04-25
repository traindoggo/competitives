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
#define rall(k) k.rbegin(), k.rend()

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;
// clang-format on

int main() {
  int n, q;
  cin >> n >> q;

  map<int, vector<int>> box;
  map<int, set<int>> cards;

  // 2 * 10^5
  rep(_, q) {
    int query;
    cin >> query;

    if (query == 1) {
      int i, j;
      cin >> i >> j;

      box[j].push_back(i);
      cards[i].insert(j);
    } else if (query == 2) {
      // box
      int i;
      cin >> i;

      // N log N
      sort(all(box[i]));
      int m = (int)box[i].size();

      // 2 * 10^5
      rep(k, m) cout << box[i][k] << (k == m - 1 ? '\n' : ' ');
    } else {
      // cards
      int i;
      cin >> i;
      int size = (int)cards[i].size();
      for (auto c : cards[i]) {
        if (size == 1)
          cout << c << el;
        else
          cout << c << ' ';
        size--;
      }
    }
  }
}
