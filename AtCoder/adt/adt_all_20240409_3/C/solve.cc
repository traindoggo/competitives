#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include <compe/debug.hpp>
#else
#define dump(...)
#endif

// clang-format off
struct  Fast{Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;

#define rep(i,n) for (int i=0; i<(int)n; ++i)
#define rrep(i,a,n) for (int i=a; i<(int)n; ++i)
#define out(msg) cout << (msg) << '\n'
#define die(msg) do{ cout << (msg) << endl,exit(0); }while(0)
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

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

bool are_pins_up(const vector<int>& pins, set<int> idxs) {
  bool is_up{false};
  for (auto idx : idxs) {
    if (pins[idx] == 1) is_up = true;
  }
  return is_up;
}

int main() {
  string s;
  cin >> s;

  if (s[0] == '1') die("No");

  // 1-index
  vector<int> pins(11, 0);
  rep(i, 10) {
    // 0 = down
    // 1 = up
    if (s[i] == '1') pins[i + 1] = 1;
  }

  bool is_split{false};

  // pin-4 split
  if (pins[4] == 0) {
    if (pins[7] == 1 && are_pins_up(pins, {2, 8, 1, 5, 3, 9, 6, 10})) {
      is_split = true;
    }
  }

  // pin-28 split
  if (pins[2] == 0 && pins[8] == 0) {
    if (are_pins_up(pins, {4, 7}) && are_pins_up(pins, {1, 5, 3, 9, 6, 10})) {
      is_split = true;
    }
  }

  // pin-15 split
  if (pins[1] == 0 && pins[5] == 0) {
    if (are_pins_up(pins, {7, 4, 2, 8}) && are_pins_up(pins, {3, 9, 6, 10})) {
      is_split = true;
    }
  }

  // pin-39 split
  if (pins[3] == 0 && pins[9] == 0) {
    if (are_pins_up(pins, {7, 4, 2, 8, 1, 5}) && are_pins_up(pins, {6, 10})) {
      is_split = true;
    }
  }

  // pin-6 split
  if (pins[6] == 0) {
    if (are_pins_up(pins, {7, 4, 2, 8, 1, 5, 3, 9}) &&
        are_pins_up(pins, {10})) {
      is_split = true;
    }
  }

  cout << (is_split ? "Yes" : "No") << el;
}
