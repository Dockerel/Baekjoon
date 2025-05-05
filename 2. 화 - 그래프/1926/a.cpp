#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, ret, maxSize;
int a[504][504];
int v[504][504];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
}

void go(int y, int x) {
  int tempSize = 1;
  ret++;
  v[y][x] = 1;
  queue<pair<int, int>> q;
  q.push({y, x});
  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      if (a[ny][nx] == 0 || v[ny][nx] == 1) continue;
      tempSize++;
      v[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
  maxSize = max(maxSize, tempSize);
}

int main() {
  fastIO;
  init();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1 && v[i][j] == 0) {
        go(i, j);
      }
    }
  }
  cout << ret << "\n" << maxSize << "\n";
  return 0;
}