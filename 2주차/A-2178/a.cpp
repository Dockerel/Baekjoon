#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m, a[104][104], visited[104][104], y, x;
string s;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  memset(visited, 0, sizeof(visited));
  return;
}

void go() {
  queue<pair<int, int>> q;
  visited[0][0] = 1;
  q.push({0, 0});
  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + "2011"[i] - '1';
      int nx = x + "1120"[i] - '1';
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
      if (visited[ny][nx]) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
  cout << visited[n - 1][m - 1] << "\n";
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}
