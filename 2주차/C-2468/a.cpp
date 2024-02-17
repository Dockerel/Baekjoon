#include <bits/stdc++.h>
using namespace std;
int n, max_nb = -INFINITY, ret, max_ret = -INFINITY, y, x, ny, nx;
int a[104][104], visited[104][104];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
void bfs(int nb) {
  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
        if (visited[ny][nx] == 0) {
          visited[ny][nx] = 1;
          if (a[ny][nx] > nb) {
            q.push({ny, nx});
          }
        }
      }
    }
  }
}
void do_bfs(int nb) {
  fill(visited[0], visited[104], 0);
  ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (visited[i][j] == 0) {
        visited[i][j] = 1;
        if (a[i][j] > nb) {
          q.push({i, j});
          ret++;
          bfs(nb);
        }
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      max_nb = max(max_nb, a[i][j]);
    }
  }
  for (int i = 0; i <= max_nb; i++) {
    do_bfs(i);
    max_ret = max(max_ret, ret);
  }
  cout << max_ret << "\n";
  return 0;
}