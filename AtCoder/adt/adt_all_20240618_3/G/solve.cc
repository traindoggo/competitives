#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/dump.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  FastIO{FastIO(){std::cin.tie(0);ios::sync_with_stdio(false);}} FastIO;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP0(n)     for (auto i=0; i<n; ++i)
#define REP1(i,n)   for (auto i=std::decay_t<decltype(n)>{}; i!=n; ++i)
#define REP2(i,l,r) for (auto i=l; i<r; ++i)
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1, REP0)(__VA_ARGS__)

#define el '\n'
#define die(msg) do{cout<<(msg)<<el;exit(0);}while(0);

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

using P = pair<int, int>;

int dy[]{1, 0, 0, -1};
int dx[]{0, 1, -1, 0};

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  // rep(i, h) dump(grid[i]);

  auto outbound = [&](int y, int x) -> bool {
    return !(0 <= y && y < h && 0 <= x && x < w);
  };

  auto on_magnet = [&](int y, int x) -> bool {
    // dump(y, x);
    if (y < h - 1 && grid[y + 1][x] == '#') return true;
    if (0 < y && grid[y - 1][x] == '#') return true;
    if (x < x + 1 && grid[y][x + 1] == '#') return true;
    if (0 < x && grid[y][x - 1] == '#') return true;
    return false;
  };

  vector seen(h, vector<bool>(w, false));
  auto dfs = [&](int sy, int sx) -> int {
    dump(sy, sx);
    int cnt{1};

    seen[sy][sx] = true;
    stack<P> st;
    st.push({sy, sx});

    set<P> magnets;

    while (!st.empty()) {
      P cur = st.top();
      st.pop();

      rep(i, 4) {
        int ny = cur.first + dy[i];
        int nx = cur.second + dx[i];

        if (outbound(ny, nx)) continue;
        if (seen[ny][nx]) continue;
        if (magnets.contains({ny, nx})) continue;

        if (on_magnet(ny, nx)) {
          // dump({ny nx});
          magnets.insert({ny, nx});
          cnt++;
          continue;
        }

        seen[ny][nx] = true;
        st.push({ny, nx});
        cnt++;
      }
    }

    return cnt;
  };

  int ans{1};
  rep(y, h) rep(x, w) {
    if (grid[y][x] == '#') continue;
    if (on_magnet(y, x)) continue;
    if (seen[y][x]) continue;
    chmax(ans, dfs(y, x));
  }
  cout << ans << el;
}
