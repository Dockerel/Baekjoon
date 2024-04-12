#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m, b, _time;
int a[504][504];
pair<int, int> ret;
void init() {
  cin >> n >> m >> b;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  ret = {1e9, -1};  // 최소시간, 최대높이
  return;
}
void go() {
  for (int h = 0; h < 257; h++) {
    int use = 0;
    int take = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] > h) {
          take += (a[i][j] - h);
        } else {
          use += (h - a[i][j]);
        }
      }
    }
    if (b + take < use) continue;
    _time = take * 2 + use;
    if (_time <= ret.first) {
      if (_time == ret.first) {
        if (h > ret.second) ret = {_time, h};
      } else {
        ret = {_time, h};
      }
    }
  }
  cout << ret.first << " " << ret.second << "\n";
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}