#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int a[54][54];
int n, m, r, c, d, ret = 0;
int y, x, ny, nx;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void init() {
  cin >> n >> m;
  cin >> r >> c >> d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  return;
}

int inRange(int yy, int xx) {
  if (yy < 0 || yy >= n || xx < 0 || xx >= m) return 0;
  return 1;
}

int check(int yy, int xx) {
  for (int i = 0; i < 4; i++) {
    ny = dy[i] + yy;
    nx = dx[i] + xx;
    if (inRange(ny, nx) && a[ny][nx] == 0) return 1;
  }
  return 0;
}

int rotate(int dd) {
  if (dd == 0) return 3;
  return dd - 1;
}

void go() {  // 0: 청소 x, 1: 벽, 2: 청소 o
  tie(y, x) = {r, c};
  while (1) {
    if (a[y][x] == 0) {
      ret++;
      a[y][x] = 2;
    }

    if (check(y, x)) {  // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
      while (1) {
        d = rotate(d);
        ny = y + dy[d];
        nx = x + dx[d];
        if (!inRange(ny, nx)) continue;
        if (a[ny][nx] == 0) {
          tie(y, x) = {ny, nx};
          break;
        }
      }
    }

    else {  // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
      ny = y - dy[d];
      nx = x - dx[d];
      if (a[ny][nx] == 1) {
        break;
      } else {
        tie(y, x) = {ny, nx};
      }
    }
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}