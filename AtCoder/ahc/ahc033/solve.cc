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
#define el '\n'

template <typename T> inline bool chmax(T& a, const T& b) {
  return ((a < b) ? (a = b, true) : false);
}
template <typename T> inline bool chmin(T& a, const T& b) {
  return ((a > b) ? (a = b, true) : false);
}
// clang-format on

int calc_output_id(const int& n, int container_id) {
  return container_id / n;
}

struct Container {
  int y, x;
  Container(int y, int x) : y(y), x(x) {}
  void set_pos(int _y, int _x) { y = _y, x = _x; }
};

// 2つの位置情報から 左右 or 上下に 何回移動するかを 文字列で出力
// (py, px) が動かしたい物の位置
// (ny, nx) が移動先の情報
string move_string(int py, int px, int ny, int nx) {
  string mv{};
  int y_diff = ny - py, x_diff = nx - px;

  if (x_diff > 0) {
    mv += string(x_diff, 'R');
  } else if (x_diff < 0) {
    mv += string(-x_diff, 'L');
  }

  if (y_diff > 0) {
    mv += string(y_diff, 'D');
  } else if (y_diff < 0) {
    mv += string(-y_diff, 'U');
  }

  return mv;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> cargos(n);
  rep(i, n) {
    rep(j, n) {
      int container;
      cin >> container;
      cargos[i].push_back(container);
    }
    reverse(cargos[i].begin(), cargos[i].end());
  }

  // first of all, break n - 1 crains
  for (int i = 0; i < n - 1; ++i) {
    cout << 'B' << el;
  }

  // set last conatiner to first pos
  Container container(n - 1, 0);

  for (int i = 0; i < n; ++i) {
    string output{};

    for (int j = 0; j < n; ++j) {
      // 今いる一度コンテナの初期位置がずれていたら修正
      output += move_string(container.y, container.x, i, 0);

      // grab a back() cargo
      int cargo_id = cargos[i].back();
      cargos[i].pop_back();
      output.push_back('P');  // graph cargo

      container.set_pos(i, 0);  // container origin position

      // calc output_id
      int output_id = calc_output_id(n, cargo_id);

      output += move_string(container.y, container.x, output_id, n - 1);

      // container move to output
      container.set_pos(output_id, n - 1);
      // and put lagguage
      output.push_back('Q');

      // back to the origin cont position
      output += move_string(container.y, container.x, i, 0);

      // bomb container
      container.set_pos(i, 0);
    }
    cout << output;
  }
  cout << el;
}
