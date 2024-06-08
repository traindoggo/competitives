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

int main() {
  int n;
  cin >> n;

  // n == 0
  if (n == 0) die("#");

  auto make_carpet = []() -> vector<string> {
    vector<string> c{"###", "#.#", "###"};
    return c;
  };

  // first carpet
  vector<string> carpet = make_carpet();

  rep(_, n - 1) {
    int size = (int)carpet.size();
    vector<string> next_carpet(3 * size, string(3 * size, '.'));

    // dump(carpet.size());
    // dump(next_carpet.size());

    // fill carpet without white center
    for (int h = 0; h < 3 * size; h += size) {
      for (int w = 0; w < 3 * size; w += size) {
        rep(y, size) rep(x, size) {
          next_carpet[h + y][w + x] = carpet[y][x];
        }
      }
    }

    // whitening ...
    for (int h = size; h < size * 2; ++h) {
      for (int w = size; w < size * 2; ++w) {
        next_carpet[h][w] = '.';
      }
    }

    // gen next ...
    carpet = next_carpet;
  }

  // output
  rep(i, (int)carpet.size()) {
    cout << carpet[i] << el;
  }
}
