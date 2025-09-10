#include <bits/stdc++.h>
using namespace std;
int n, m, ret = -1, y, x, ny, nx;
string s;
char mp[54][54];
int v[54][54];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> lands;

void bfs(pair<int, int> land) {
  int mx = -1;
  queue<pair<int, int>> Q;

  Q.push(land);
  while (!Q.empty()) {
    tie(y, x) = Q.front();  // *
    Q.pop();

    for (int i = 0; i < 4; i++) {
      ny = y + dy[i];
      nx = x + dx[i];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx] != 'L' ||
          v[ny][nx])
        continue;
      v[ny][nx] = v[y][x] + 1;
      Q.push({ny, nx});
      mx = max(mx, v[ny][nx]);
    }
  }

  ret = max(ret, mx);
}

void Solution() {
  for (auto land : lands) {
    memset(v, 0, sizeof(v));         // *
    v[land.first][land.second] = 1;  // *
    bfs(land);
  }
}

void Input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'L') lands.push_back({i, j});
      mp[i][j] = s[j];
    }
  }
}

void Solve() {
  Input();
  Solution();
  cout << ret - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();
}
