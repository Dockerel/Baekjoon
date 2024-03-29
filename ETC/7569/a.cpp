#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int m, n, h, z, y, x, ret, flag;
int a[104][104][104], v[104][104][104];
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dx[6] = {0, 0, 1, -1, 0, 0};
queue<tuple<int, int, int>> Q, tempQ;

void swap_queue(queue<tuple<int, int, int>> &temp) {
  queue<tuple<int, int, int>> empty;
  swap(temp, empty);
  return;
}

void init() {
  flag = 1;
  ret = 0;
  memset(v, 0, sizeof(v));

  cin >> m >> n >> h;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        cin >> a[i][j][k];
        if (a[i][j][k] == 0) flag = 0;
        if (a[i][j][k] == 1) {
          Q.push({i, j, k});
          v[i][j][k] = 1;
        }
      }
    }
  }
  return;
}

void go() {
  // 모두 익어있는 케이스
  if (flag) {
    cout << "0\n";
    exit(0);
  }

  while (1) {
    while (!Q.empty()) {
      tie(z, y, x) = Q.front();
      Q.pop();
      for (int i = 0; i < 6; i++) {
        int nz = dz[i] + z;
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
          continue;
        if (v[nz][ny][nx] == 1) continue;
        if (a[nz][ny][nx] == 0) {
          a[nz][ny][nx] = 1;
          tempQ.push({nz, ny, nx});
        }
      }
    }

    if (tempQ.empty()) break;
    Q = tempQ;
    swap_queue(tempQ);
    ret++;
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (a[i][j][k] == 0) {
          cout << "-1\n";
          exit(0);
        }
      }
    }
  }
  cout << ret << "\n";
  return;
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}