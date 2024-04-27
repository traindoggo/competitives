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

void input(queue<char> &que) {
  string s;
  cin >> s;
  for (auto ch : s) {
    que.push(ch);
  }
}
int main() {
  queue<char> qa, qb, qc;
  input(qa);
  input(qb);
  input(qc);

  char turn = qa.front();
  qa.pop();

  while (true) {
    if (turn == 'a') {
      if (qa.empty()) die("A");
      turn = qa.front();
      qa.pop();
    } else if (turn == 'b') {
      if (qb.empty()) die("B");
      turn = qb.front();
      qb.pop();
    } else {
      if (qc.empty()) die("C");
      turn = qc.front();
      qc.pop();
    }
  }
}
