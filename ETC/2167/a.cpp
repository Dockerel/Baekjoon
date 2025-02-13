#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, k, yy, x1, y2, x2, ret;
int a[304][304];

void init() {
  cin >> n >> m;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    int _prev = 0;
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] += _prev;
      _prev = a[i][j];
    }
  }
  cin >> k;
}

void go() {
  for (int _ = 0; _ < k; _++) {
    ret = 0;
    cin >> yy >> x1 >> y2 >> x2;
    for (int i = yy; i <= y2; i++) {
      ret += (a[i][x2] - a[i][x1 - 1]);
    }
    cout << ret << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}