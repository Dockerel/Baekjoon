#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int maze[5][5][5];
int board[5][5][5];
int ret = 125;

struct Point {
  int z;
  int y;
  int x;
};

queue<Point> q;
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};
int v[5][5][5];
int dist[5][5][5];

void init() {
  memset(v, 0, sizeof(v));
  memset(dist, 0, sizeof(dist));
}

void rotate(int level) {
  int temp[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      temp[i][j] = maze[level][5 - j - 1][i];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      maze[level][i][j] = temp[i][j];
    }
  }
}

int bfs(int z, int y, int x) {
  init();
  q.push({z, y, x});
  v[z][y][x] = 1;
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nz = cur.z + dz[i];
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];
      if (nz < 0 || nz >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
      if (!maze[nz][ny][nx] || v[nz][ny][nx]) continue;
      v[nz][ny][nx] = 1;
      dist[nz][ny][nx] = dist[cur.z][cur.y][cur.x] + 1;
      q.push({nz, ny, nx});
    }
  }
  if (dist[4 - z][4 - y][4 - x]) return dist[4 - z][4 - y][4 - x];
  return 125;
}

void solve(int depth) {
  if (depth == 5) {
    int temp;
    if (maze[0][0][0] == 1 && maze[4][4][4] == 1) {
      temp = bfs(0, 0, 0);
      ret = min(ret, temp);
    }
    if (maze[0][4][0] == 1 && maze[4][0][4] == 1) {
      temp = bfs(0, 4, 0);
      ret = min(ret, temp);
    }
    if (maze[0][4][4] == 1 && maze[4][0][0] == 1) {
      temp = bfs(0, 4, 4);
      ret = min(ret, temp);
    }
    if (maze[0][0][4] == 1 && maze[4][4][0] == 1) {
      temp = bfs(0, 0, 4);
      ret = min(ret, temp);
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < i; j++) rotate(depth);
    solve(depth + 1);
    for (int j = 0; j < 4 - i; j++) rotate(depth);
  }
}

int main() {
  fastIO;
  vector<int> arr{0, 1, 2, 3, 4};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        cin >> board[i][j][k];
      }
    }
  }

  do {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
          maze[i][j][k] = board[arr[i]][j][k];
        }
      }
    }
    solve(0);
  } while (next_permutation(arr.begin(), arr.end()));

  if (ret == 125)
    cout << "-1\n";
  else
    cout << ret << "\n";
  return 0;
}