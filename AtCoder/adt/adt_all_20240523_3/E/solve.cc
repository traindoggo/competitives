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

using ll = long long int;
// clang-format on

int main() {
  int n;
  cin >> n;

  vector<ll> ai(n);
  rep(i, n) cin >> ai[i];

  vector<ll> bi = ai;
  sort(bi.rbegin(), bi.rend());

  map<ll, ll> counter;
  for (auto b : bi) {
    counter[b]++;
  }

  map<ll, ll> mp;
  ll prev{};

  bi.erase(unique(bi.begin(), bi.end()), bi.end());
  sort(bi.rbegin(), bi.rend());

  for (auto b : bi) {
    mp[b] = prev;
    prev += b * counter[b];
  }

  rep(i, n) {
    cout << mp[ai[i]] << (i != n - 1 ? ' ' : '\n');
  }
}
