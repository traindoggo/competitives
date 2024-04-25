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

int dh[]{0, -1, 1, 0};
int dw[]{-1, 0, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> vs(h);
  rep(i, h) cin >> vs[i];

  string snuke{"snuke"};
  vector visited(h, vector<int>(w, false));

  auto dfs = [&](auto f, int y, int x, int step) -> void {
    visited[y][x] = true;
    step %= 5;

    rep(i, 4) {
      int nh = y + dh[i];
      int nw = x + dw[i];

      if (!(0 <= nh and nh < h and 0 <= nw and nw < w)) continue;

      // current -> next
      if (snuke[step] != vs[y][x]) continue;
      if (snuke[(step + 1) % 5] != vs[nh][nw]) continue;
      if (visited[nh][nw]) continue;

      f(f, nh, nw, step + 1);
    }
  };

  dfs(dfs, 0, 0, 0);

  if (visited[h - 1][w - 1])
    cout << "Yes" << el;
  else
    cout << "No" << el;
}
