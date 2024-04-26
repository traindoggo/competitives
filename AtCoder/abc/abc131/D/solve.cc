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

using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  vector<P> works;
  rep(_, n) {
    int a, b;
    cin >> a >> b;
    works.push_back({a, b});
  }

  auto compare = [](const P& a, const P& b) -> bool {
    if (a.second < b.second) return true;
    return false;
  };

  sort(works.begin(), works.end(), compare);

  int cur{};
  for (auto [a, b] : works) {
    cur += a;
    if (cur > b) {
      die("No");
    }
  }

  cout << "Yes" << el;
}
