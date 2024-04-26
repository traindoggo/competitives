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

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;

  vector<char> st;
  int open{};

  for (auto ch : s) {
    if (ch == '(') {
      st.push_back(ch);
      open++;
    } else if (ch == ')') {
      if (open == 0) {
        st.push_back(ch);
        continue;
      }

      while (!st.empty() && open > 0) {
        if (st.back() == '(') {
          st.pop_back();
          open--;
          break;
        } else {
          st.pop_back();
        }
      }
    } else {
      st.push_back(ch);
    }
  }

  for (auto ch : st) cout << ch;
  cout << el;
}
