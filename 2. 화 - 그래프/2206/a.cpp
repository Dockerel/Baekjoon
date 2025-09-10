#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1004
#define tiiii tuple<int, int, int, int>

using namespace std;

int n, m;
int a[MAX][MAX];
string s;

int visited[MAX][MAX][2];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int y, x, cnt, breakW;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  memset(visited, 0, sizeof(visited));
}

void go() {
  queue<tiiii> q;
  q.push({0, 0, 1, 0});

  visited[0][0][0] = 1;

  while (!q.empty()) {
    tie(y, x, cnt, breakW) = q.front();
    q.pop();

    if (y == n - 1 && x == m - 1) {
      cout << cnt << "\n";
      return;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx][breakW])
        continue;
      if (a[ny][nx] == 0) {
        visited[ny][nx][breakW] = 1;
        q.push({ny, nx, cnt + 1, breakW});
      } else {
        if (breakW == 0) {
          visited[ny][nx][1] = 1;
          q.push({ny, nx, cnt + 1, 1});
        }
      }
    }
  }
  cout << "-1\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}