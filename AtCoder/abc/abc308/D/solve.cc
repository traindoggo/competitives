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

int dy[]{0, 1, -1, 0};
int dx[]{1, 0, 0, -1};

using P = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;

  string snuke{"snuke"};

  vector<string> vs(h);
  rep(i, h) cin >> vs[i];
  if (vs[0][0] != 's') die("No");

  auto nxt = [&](int y, int x) {
    char ch = vs[y][x];
    int idx = snuke.find(ch);
    return snuke[(idx + 1) % 5];
  };

  vector<vector<bool>> seen(h, vector<bool>(w, false));

  auto dfs = [&](int sy, int sx) {
    seen[sy][sx] = true;

    // use stack - 普通にWAりそう
    stack<P> st;
    st.push({sy, sx});

    while (!st.empty()) {
      auto [y, x] = st.top();
      st.pop();

      rep(i, 4) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
        if (vs[ny][nx] != nxt(y, x)) continue;
        if (seen[ny][nx]) continue;
        seen[ny][nx] = true;
        st.push({ny, nx});
      }
    }
  };

  dfs(0, 0);

  YesNo(seen[h - 1][w - 1]);
}
