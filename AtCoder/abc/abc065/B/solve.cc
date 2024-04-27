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
  int n;
  cin >> n;
  vector<int> ai(n);
  rep(i, n) cin >> ai[i], ai[i]--;

  set<int> pushed;
  pushed.insert(0);

  int button{0}, cnt{};

  while (true) {
    button = ai[button];
    cnt++;
    if (pushed.contains(button)) {
      die(-1);
    }

    if (button == 1) {
      die(cnt);
    }

    pushed.insert(button);
  }
}
