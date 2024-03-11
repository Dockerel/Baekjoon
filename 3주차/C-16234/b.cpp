#include <bits/stdc++.h>
using namespace std;
int n, l, r, sum, ret = 0;
int y, x, ny, nx;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int a[54][54], visited[54][54];
vector<pair<int, int>> v;
queue<pair<int, int>> q;

void bfs(int y, int x) {
  q.push({y, x});
  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      ny = dy[k] + y;
      nx = dx[k] + x;
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
      if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
        visited[ny][nx] = 1;
        v.push_back({ny, nx});
        sum += a[ny][nx];
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  while (1) {
    int flag = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!visited[i][j]) {
          v.clear();
          visited[i][j] = 1;
          v.push_back({i, j});
          sum = a[i][j];

          bfs(i, j);

          if (v.size() == 1) continue;
          for (auto b : v) {
            a[b.first][b.second] = sum / v.size();
            flag = 1;
          }
        }
      }
    }
    if (!flag) break;
    ret++;
  }

  cout << ret << "\n";
  return 0;
}