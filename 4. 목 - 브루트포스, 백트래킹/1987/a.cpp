#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int r, c, ret = -1;
char a[24][24];
int v[28];
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
  memset(v, 0, sizeof(v));
  v[a[0][0] - 'A'] = 1;
}

void go(int y, int x, int path) {
  ret = max(ret, path);
  for (int i = 0; i < 4; i++) {
    int ny = dy[i] + y;
    int nx = dx[i] + x;
    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
    if (v[a[ny][nx] - 'A'] == 1) continue;
    v[a[ny][nx] - 'A'] = 1;
    go(ny, nx, path + 1);
    v[a[ny][nx] - 'A'] = 0;
  }
}

int main() {
  fastIO;
  init();
  go(0, 0, 1);
  cout << ret << "\n";
  return 0;
}
