#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, next_y, next_x, ret;
int a[104][104], visited[104][104];
char line[104];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

queue<pair<pair<int, int>, int>> q;

void bfs() {
  while (!q.empty()) {
    y = q.front().first.first;
    x = q.front().first.second;
    ret = q.front().second;
    q.pop();

    if (y == n - 1 && x == m - 1) {
      cout << ret + 1;
      return;
    }

    for (int i = 0; i < 4; i++) {
      next_y = y + dy[i];
      next_x = x + dx[i];
      if (visited[next_y][next_x] == 0 && a[next_y][next_x] == 1 && x >= 0 &&
          y >= 0 && x < m && y < n) {
        visited[next_y][next_x] = 1;
        q.push({{next_y, next_x}, ret + 1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // input
  cin >> n >> m;
  for (int j = 0; j < n; j++) {
    cin >> line;
    for (int i = 0; i < strlen(line); i++)
      if (line[i] == '1') a[j][i] = 1;
  }

  //   find route
  visited[0][0] = 1;
  q.push({{0, 0}, 0});
  bfs();

  return 0;
}