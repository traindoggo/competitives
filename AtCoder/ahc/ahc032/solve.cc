#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
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

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

using Stamp = vector<vector<llint>>;

string conv(int idx, int h, int w) {
  return to_string(idx) + " " + to_string(h) + " " + to_string(w);
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector grid(n, vector<llint>(n, 0));
  rep(i, n) rep(j, n) cin >> grid[i][j];

  //     0         1
  // [n, n, n] [n, n, n]
  // [n, n, n] [n, n, n]
  // [n ,n ,n] [n, n, n]
  vector<Stamp> stamps(m, Stamp(3, vector<llint>(3, 0)));
  rep(i, m) rep(j, 3) rep(k, 3) cin >> stamps[i][j][k];

  /*
   * Main
   * */
  vector<string> ans;
  int prev_ans_size{}, cnt{};

  // *** k times search at most
  while (true) {
    // *** stamp rally
    llint max_ave{};
    int good_h{-1}, good_w{-1};
    int stamp_id{};

    // *** all stamps
    rep(s, m) {
      Stamp stamp = stamps[s];

      // *** search all grids
      rep(h, n - 2) rep(w, n - 2) {
        llint diff_total{};

        // O(k * m * n * n * 3 * 3)
        // O(81 * 20 * 9 * 9 * 3 * 3)
        // O(1180980)
        rep(i, 3) rep(j, 3) {
          llint before = grid[h + i][w + j];
          llint after = (grid[h + i][w + j] + stamp[i][j]) % MOD98;
          diff_total += (after - before);
        }

        if (diff_total > 0 && chmax(max_ave, diff_total / 9)) {
          good_h = h;
          good_w = w;
          stamp_id = s;
        }
      }
    }

    // *** update origin grid
    if (good_h >= 0 && good_w >= 0) {
      rep(h, 3) rep(w, 3) {
        grid[good_h + h][good_w + w] += stamps[stamp_id][h][w];
        grid[good_h + h][good_w + w] %= MOD98;
      }

      ans.push_back(conv(stamp_id, good_h, good_w));
    }

    // force termination of searching
    if ((int)ans.size() >= k) break;

    if (prev_ans_size != (int)ans.size()) {
      prev_ans_size = ans.size();
    } else {
      // no updated
      if (cnt++ > 20) break;
    }
  }

  cout << ans.size() << el;
  rep(i, min((int)ans.size(), k)) {
    cout << ans[i] << el;
  }
}
