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
  int n, m;
  cin >> n >> m;
  vector<int> ai(n), bi(m);
  vector<int> merged;
  rep(i, n) {
    cin >> ai[i];
    merged.push_back(ai[i]);
  }
  rep(i, m) {
    cin >> bi[i];
    merged.push_back(bi[i]);
  }

  sort(all(merged));

  vector<int> ai_idx, bi_idx;
  int left{}, right{}, idx{};

  while (idx < n + m) {
    if (left < n && ai[left] == merged[idx]) {
      ai_idx.push_back(idx + 1);
      left++;
    } else if (right < m && bi[right] == merged[idx]) {
      bi_idx.push_back(idx + 1);
      right++;
    }
    idx++;
  }

  rep(i, (int)ai_idx.size()) {
    cout << ai_idx[i] << (i != (int)ai_idx.size() - 1 ? ' ' : '\n');
  }

  rep(i, (int)bi_idx.size()) {
    cout << bi_idx[i] << (i != (int)bi_idx.size() - 1 ? ' ' : '\n');
  }
}
