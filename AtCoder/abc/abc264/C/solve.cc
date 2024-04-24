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

// const
#define INFi  1   << 30
#define INFll 1LL << 60
#define MOD17 10'0000'0007
#define MOD98  9'9824'4353

// alias
using ullint = unsigned long long int;
using llint  = long long int;
// clang-format on

using vvi = vector<vector<int>>;

vvi input(const int h, const int w) {
  vector tmp(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> tmp[i][j];
  return tmp;
}

int main() {
  int H1, W1;
  cin >> H1 >> W1;
  vvi A = input(H1, W1);

  int H2, W2;
  cin >> H2 >> W2;
  vvi B = input(H2, W2);

  // choice row
  for (int bit = 0; bit < (1 << H1); ++bit) {
    vvi rows;
    for (int i = 0; i < H1; ++i) {
      if (bit & (1 << i)) {
        rows.push_back(A[i]);
      }
    }

    // choice col elems
    for (int bit1 = 0; bit1 < (1 << W1); ++bit1) {
      vvi res;
      for (int h = 0; h < (int)rows.size(); ++h) {
        vector<int> row;
        for (int j = 0; j < W1; ++j) {
          if (bit1 & (1 << j)) {
            row.push_back(rows[h][j]);
          }
        }
        res.push_back(row);
      }

      if (res == B) die("Yes");
    }
  }

  cout << "No" << el;
}
