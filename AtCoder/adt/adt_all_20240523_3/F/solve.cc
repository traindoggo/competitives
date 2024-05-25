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

#define INFi  1   << 30
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}

using ll = long long int;
// clang-format on

int main() {
  int n;
  cin >> n;
  vector<string> slots(n);
  rep(i, n) cin >> slots[i];

  auto measure_time = [](const char num, const int n,
                         vector<string> slot) -> int {
    int mt{};
    int cnt{n}, idx{0};

    while (true) {
      rep(i, n) {
        if (slot[i][idx] == num) {
          slot[i][idx] = '.';
          cnt--;
          break;
        }
      }

      if (cnt == 0) break;

      idx = (idx + 1) % 10;
      mt++;
    }

    return mt;
  };

  string nums{"0123456789"};
  int min_time{INFi};
  for (auto num : nums) {
    chmin(min_time, measure_time(num, n, slots));
  }
  cout << min_time << el;
}
