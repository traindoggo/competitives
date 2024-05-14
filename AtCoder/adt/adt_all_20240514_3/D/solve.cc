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

bool is_good_suite(char ch) {
  return ch == 'H' || ch == 'D' || ch == 'C' || ch == 'S';
}

bool is_good_number(char ch) {
  vector<char> marks{'A', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'T', 'J', 'Q', 'K'};
  for (char m : marks) {
    if (ch == m) return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;

  set<string> st;
  rep(_, n) {
    string s;
    cin >> s;

    if (!is_good_suite(s[0]) || !is_good_number(s[1]) || st.contains(s)) {
      die("No");
    }
    st.insert(s);
  }

  cout << "Yes" << el;
}
