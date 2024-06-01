#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define el '\n'
#define rep(i,n) for (int i=0;i<(int)n;++i)
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

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<set<int>> inserts;
  vector<bool> results;

  rep(i, m) {
    int c;
    cin >> c;

    set<int> tried;
    rep(_, c) {
      int a;
      cin >> a;
      tried.insert(a - 1);
    }

    inserts.push_back(tried);

    char res;
    cin >> res;
    results.push_back(res == 'o');
  }

  int ans{};

  rep(bit, 1 << n) {
    // correct or dummy
    vector<bool> keys;

    rep(z, n) {
      if (bit & (1 << z)) {
        keys.push_back(true);
      } else {
        keys.push_back(false);
      }
    }

    vector<int> count(m);
    rep(i, n) {
      // Suppose keys[i] is correct.
      if (keys[i] == true) {
        rep(j, m) {
          if (inserts[j].contains(i)) {
            count[j]++;
          }
        }
      }
    }

    // check
    vector<bool> checker;
    rep(i, m) {
      // good test
      if (count[i] >= k) {
        checker.push_back(true);
      } else {
        checker.push_back(false);
      }
    }

    bool is_good_try{true};
    rep(i, m) {
      if (checker[i] != results[i]) {
        is_good_try = false;
      }
    }
    if (is_good_try) ans++;
  }

  cout << ans << el;
}
