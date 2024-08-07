#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/dump.hpp>
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

using P = pair<int, int>;

struct compare {
  bool operator()(const P& a, const P& b) { return a.second > b.second; }
};

int main() {
  int n;
  cin >> n;

  priority_queue<P, vector<P>, compare> que;

  rep(i, n) {
    int l, r;
    cin >> l >> r;
    que.push({l, r});
  }

  int cnt{};
  int cur_time{0};

  while (!que.empty()) {
    P p = que.top();
    dump(p);
    que.pop();
    if (cur_time <= p.first) {
      cnt++;
      chmax(cur_time, p.second);
    }
  }

  cout << cnt << el;
}
