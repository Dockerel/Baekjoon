#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int r, c, ret = -1;
char a[24][24];
int v;
int y, x;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  v |= (1 << (a[0][0] - 'A'));
}

void go(int y, int x, int path) {
  ret = max(ret, path);
  for (int i = 0; i < 4; i++) {
    int ny = dy[i] + y;
    int nx = dx[i] + x;
    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
    if (v & (1 << (a[ny][nx] - 'A'))) continue;
    v |= (1 << (a[ny][nx] - 'A'));
    go(ny, nx, path + 1);
    v &= ~(1 << (a[ny][nx] - 'A'));
  }
}

int main() {
  fastIO;
  init();
  go(0, 0, 1);
  cout << ret << "\n";
  return 0;
}
