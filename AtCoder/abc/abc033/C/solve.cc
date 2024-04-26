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
  string s;
  cin >> s;
  s.push_back('+');

  vector<string> terms;

  int prev{0};
  rep(i, (int)s.size()) {
    if (s[i] == '+') {
      terms.push_back(s.substr(prev, i - prev));
      prev = i + 1;
    }
  }

  int cnt{};

  for (auto term : terms) {
    bool has_zero{false};
    for (auto ch : term) {
      if (ch == '0') has_zero = true;
    }

    if (!has_zero) cnt++;
  }

  cout << cnt << el;
}
