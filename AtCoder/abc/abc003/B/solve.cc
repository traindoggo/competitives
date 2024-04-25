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

bool is_atcoder(char ch) {
  return set<char>{'a', 't', 'c', 'o', 'd', 'e', 'r'}.contains(ch);
}

int main() {
  string s, t;
  cin >> s >> t;

  int n = (int)s.size();
  rep(i, n) {
    if (s[i] == t[i]) continue;
    if (s[i] == '@' and t[i] != '@') {
      if (is_atcoder(t[i])) continue;
    } else if (s[i] != '@' and t[i] == '@') {
      if (is_atcoder(s[i])) continue;
    }
    die("You will lose");
  }

  cout << "You can win" << el;
}
