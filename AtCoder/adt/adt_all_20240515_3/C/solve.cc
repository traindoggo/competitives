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

int main() {
  int n;
  cin >> n;

  vector<set<int>> vss(n);
  rep(i, n) {
    int c;
    cin >> c;
    rep(_, c) {
      int cc;
      cin >> cc;
      vss[i].insert(cc);
    }
  }

  int x;
  cin >> x;

  vector<pair<int, int>> hit;
  rep(i, n) {
    auto st = vss[i];
    if (st.contains(x)) {
      hit.push_back(make_pair(st.size(), i + 1));
    }
  }

  if (hit.size() == 0) {
    cout << 0 << el;
    die("");
  }

  sort(all(hit));

  int min_size{100};
  for (auto [size, idx] : hit) {
    chmin(min_size, size);
  }

  vector<int> ans;
  for (auto [size, idx] : hit) {
    if (size == min_size) {
      ans.push_back(idx);
    }
  }

  int size = (int)ans.size();
  cout << size << el;
  rep(i, size) {
    cout << ans[i] << (i != size - 1 ? ' ' : '\n');
  }
}
