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

/*
 * ai の因数をすべて求める
 * set<int> に打ち込む
 *
 * 1 <= k <= M を全探索
 * 割り切れなかったものを出力
 * ! k = 1 は必ず問題を満たす
 * */
void prime_factor(int a, set<int>& st) {
  for (int i = 2; i * i <= a; ++i) {
    while (a % i == 0) {
      st.insert(i);
      a /= i;
    }
  }

  if (a > 0) {
    st.insert(a);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> ai(n);
  rep(i, n) cin >> ai[i];

  set<int> st;
  st.insert(1);

  // 10^5
  for (auto a : ai) {
    // Log a, a <= 10^5
    prime_factor(a, st);
  }
  st.erase(1);

  vector<int> ans;
  // 10^5
  for (int k = 1; k <= m; ++k) {
    bool is_good{true};

    // ???
    for (auto factor : st) {
      if (k % factor == 0) {
        is_good = false;
      }

      if (is_good) break;
    }

    if (is_good) {
      ans.push_back(k);
    }
  }

  sort(all(ans));
  cout << ans.size() << el;
  for (auto a : ans) {
    cout << a << el;
  }
}
