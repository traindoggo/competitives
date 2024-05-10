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

using P = pair<char, int>;

vector<P> compress(const string& s) {
  int prev{};
  vector<P> tmp;
  rep(i, (int)s.size()) {
    if (s[i] != s[i + 1]) {
      tmp.push_back({s[i], (i + 1) - prev});
      prev = i + 1;
    }
  }
  tmp.pop_back();

  return tmp;
}

void solve() {
  string s;
  cin >> s;
  s.push_back('+');  // sentinel

  vector<P> pairs = compress(s);

  // 0...01...1
  bool exist_sorted_pair{false};

  int n = (int)pairs.size();
  rep(i, n - 1) {
    if (pairs[i].first == '0' && pairs[i + 1].first == '1') {
      exist_sorted_pair = true;
    }
  }

  if (n == 1) {
    cout << 1 << el;
    return;
  }

  if (exist_sorted_pair) {
    cout << n - 2 + 1 << el;
  } else {
    cout << n << el;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
