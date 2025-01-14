#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1028

using namespace std;

int n, m;
int a[MAX][MAX];
int _x1, _y1, _x2, _y2;
int _sum[MAX][MAX];
int ret;

void init() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  // 누적합 만들기
  memset(_sum, 0, sizeof(_sum));
  for (int i = 1; i <= n; i++) {
    _sum[i][1] = a[i][1];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      _sum[i][j] = _sum[i][j - 1] + a[i][j];
    }
  }
}

void go() {
  ret = 0;
  for (int i = _x1; i <= _x2; i++) {
    ret += (_sum[i][_y2] - _sum[i][_y1 - 1]);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < m; _++) {
    cin >> _x1 >> _y1 >> _x2 >> _y2;
    go();
  }
  return 0;
}