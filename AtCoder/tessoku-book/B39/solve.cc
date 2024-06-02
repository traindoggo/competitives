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

bool is_good_sequence(int N, int K, vector<int>& A, vector<int>& result) {
  // 数列をソートする
  sort(A.begin(), A.end());

  // 累積和を計算
  vector<int> cumulative_sum(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    cumulative_sum[i] = cumulative_sum[i - 1] + A[i - 1];
  }

  // 良い数列にできるか判定
  for (int i = 1; i <= N; ++i) {
    if (cumulative_sum[i] >= K) {
      // A の最初の i 個を取り、残りを後に付ける
      result.insert(result.end(), A.begin(), A.begin() + i);
      result.insert(result.end(), A.begin() + i, A.end());
      return true;
    }
  }

  return false;
}

int main() {
  int N, K;
  cout << "N と K を入力してください: ";
  cin >> N >> K;
  vector<int> A(N);
  cout << "数列 A を入力してください: ";
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<int> result;
  if (is_good_sequence(N, K, A, result)) {
    cout << "YES" << endl;
    for (int i = 0; i < N; ++i) {
      cout << result[i] << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
