#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
char maze[54][54];
int visited[54][54][1 << 6];
string s;
pair<int, int> start;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      maze[i][j] = s[j];
      if (s[j] == '0') {
        start = {i, j};
        maze[i][j] = '.';
      }
    }
  }
  memset(visited, 0, sizeof(visited));
}

bool hasKey(int key, char door) {
  int _stat = key & (1 << (int(door) - 'A'));
  if (_stat != 0) return true;
  return false;
}

int go(pair<int, int> pos) {
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push({pos, {0, 0}});
  visited[pos.first][pos.second][0] = 1;

  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front().first;
    int cnt, key;
    tie(cnt, key) = q.front().second;
    q.pop();

    if (maze[y][x] == '1') return cnt;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx][key])
        continue;
      if (maze[ny][nx] == '.' || maze[ny][nx] == '1') {
        visited[ny][nx][key] = 1;
        q.push({{ny, nx}, {cnt + 1, key}});
      } else if ('a' <= maze[ny][nx] && maze[ny][nx] <= 'f') {
        int tempKey = key | (1 << (int(maze[ny][nx]) - 'a'));
        visited[ny][nx][tempKey] = 1;
        q.push({{ny, nx}, {cnt + 1, tempKey}});
      } else if ('A' <= maze[ny][nx] && maze[ny][nx] <= 'F') {
        if (hasKey(key, maze[ny][nx])) {
          visited[ny][nx][key] = 1;
          q.push({{ny, nx}, {cnt + 1, key}});
        }
      }
    }
  }
  return -1;
}

int main() {
  fastIO;
  init();
  cout << go(start) << "\n";
  return 0;
}