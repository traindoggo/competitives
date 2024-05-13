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

struct Coin {
  int coin1, coin5, coin10, coin50, coin100, coin500;
};

namespace me {
int sum(const vector<int>& ai) {
  int s{};
  for (auto a : ai) s += a;
  return s;
}
}  // namespace me

int main() {
  vector<int> coins(10);
  rep(i, 6) cin >> coins[i];

  int n;
  cin >> n;

  vector<int> xi(n);
  rep(i, n) cin >> xi[i];

  const int DIGIT_SIZE = 5;
  vector<vector<int>> digits(DIGIT_SIZE);

  // xi's biggest length : "99999" = 5
  rep(i, DIGIT_SIZE) {
    for (auto& x : xi) {
      digits[i].push_back(x % 10);
      x /= 10;
    }
  }

  rep(i, DIGIT_SIZE) {
    int small = 2 * i;
    int big = 2 * i + 1;

    // まずは大きい方で割る
    rep(j, n) {
      if (digits[i][j] >= 5 && coins[big] >= 1) {
        digits[i][j] -= 5;
        coins[big]--;
      }
    }

    // 残りの総和
    int sum = me::sum(digits[i]);

    // not enough your coins
    if (sum != 0 && sum > coins[small]) {
      die("No");
    }

    // enough to pay :^)
    coins[small] -= sum;
    rep(j, n) digits[i][j] = 0;  // zero

    // carry up ; 繰り上げ
    if (coins[small] >= 10) {
      coins[big + 1] += coins[small] / 10;
      coins[small] %= 10;
    }

    if (coins[small] >= 5) {
      coins[big] += coins[small] / 5;
      coins[small] %= 5;
    }

    if (coins[big] >= 2) {
      coins[big + 1] += coins[big] / 2;
      coins[big] %= 2;
    }
  }

  rep(i, DIGIT_SIZE) {
    for (auto d : digits[i]) {
      if (d != 0) die("No");
    }
  }

  cout << "Yes" << el;
}
