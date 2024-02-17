#include <bits/stdc++.h>
using namespace std;
int m, n, k;
int x_1, y_1, x_2, y_2;
int x, y, nx, ny;
int ret = 0, area;

int a[104][104], v[104][104], areas[104];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

queue<pair<int, int>> q;

void bfs() {
  area = 1;
  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny >= 0 && nx >= 0 && ny < m && nx < n)
        if (v[ny][nx] == 0) {
          v[ny][nx] = 1;
          if (a[ny][nx] == 0) {
            area++;
            q.push({ny, nx});
          }
        }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    for (int j = y_1; j < y_2; j++) {
      for (int l = x_1; l < x_2; l++) {
        a[j][l] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] == 0) {
        v[i][j] = 1;
        if (a[i][j] == 0) {
          q.push({i, j});
          bfs();
          areas[ret++] = area;
        }
      }
    }
  }

  cout << ret << "\n";
  sort(areas, areas + ret);
  for (int i = 0; i < ret; i++) {
    cout << areas[i] << " ";
  }

  return 0;
}