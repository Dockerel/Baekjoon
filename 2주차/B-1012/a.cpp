#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, x, y, ret, next_y, next_x;
int a[54][54], visited[54][54];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
void bfs() {
  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      next_y = y + dy[i];
      next_x = x + dx[i];
      if (a[next_y][next_x] == 1 && visited[next_y][next_x] == 0) {
        visited[next_y][next_x] = 1;
        q.push({next_y, next_x});
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for (int t1 = 0; t1 < t; t1++) {
    cin >> m >> n >> k;
    ret = 0;
    fill(a[0], a[54], 0);
    fill(visited[0], visited[54], 0);
    for (int i = 0; i < k; i++) {
      cin >> x >> y;
      a[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1 && visited[i][j] == 0) {
          visited[i][j] == 1;
          ret++;
          q.push({i, j});
          bfs();
        }
      }
    }
    cout << ret << "\n";
  }
  return 0;
}