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

using llint  = long long int;
// clang-format on

int main() {
  string s;
  cin >> s;

  auto is_oku = [](char ch) { return ch == 'o' || ch == 'k' || ch == 'u'; };

  int n = (int)s.size();
  rep(i, n) {
    if (is_oku(s[i])) {
      continue;
    }

    if (i < n && s[i] == 'c' && s[i + 1] == 'h') {
      i++;
      continue;
    }

    die("NO");
  }

  cout << "YES" << el;
}
