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

void merge(vector<int>& s, int left, int mid, int right, int& cnt) {
  int n1 = mid - left;
  int n2 = right - mid;

  vector<int> l, r;
  rep(i, n1 + 1) l.push_back(i);
  rep(i, n2 + 1) r.push_back(i);

  rep(i, n1) l[i] = s[left + i];
  rep(i, n2) r[i] = s[mid + i];

  l[n1] = INFi;
  r[n2] = INFi;

  int i = 0, j = 0;

  for (int k = left; k < right; ++k) {
    if (l[i] <= r[j]) {
      s[k] = l[i];
      i++;
      cnt++;
    } else {
      s[k] = r[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(vector<int>& s, int left, int right, int& cnt) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(s, left, mid, cnt);
    mergeSort(s, mid, right, cnt);
    merge(s, left, mid, right, cnt);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];

  int cnt{};
  mergeSort(s, 0, n, cnt);

  rep(i, n) {
    cout << s[i] << (i == n - 1 ? '\n' : ' ');
  }

  cout << cnt << el;
}
