#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
int sea[304][304];
int visited[304][304];

vector<pair<int, int>> ice;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> sea[i][j];
      if (sea[i][j] != 0) {
        ice.push_back({i, j});
      }
    }
  }
}

bool isSplit() {
  int pieces = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }

  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (sea[i][j] != 0 && visited[i][j] == 0) {
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty()) {
          int y, x;
          tie(y, x) = q.front();
          q.pop();
          for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m ||
                visited[ny][nx] == 1 || sea[ny][nx] == 0)
              continue;
            visited[ny][nx] = 1;
            q.push({ny, nx});
          }
        }
        pieces += 1;
      }
    }
  }

  return pieces > 1;
}

void go() {
  int ret = 0;
  while (!isSplit()) {
    if (ice.empty()) {
      cout << 0 << "\n";
      return;
    }

    vector<pair<int, int>> new_ice;
    int melt[304][304];

    // 1단계: 녹을 양 계산 (원본 sea 배열 기준)
    for (auto it : ice) {
      int y = it.first, x = it.second;
      int water_count = 0;

      for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && sea[ny][nx] == 0) {
          water_count++;
        }
      }

      melt[y][x] = water_count;  // 녹을 양만 저장
    }

    // 2단계: 동시에 녹이기
    for (auto it : ice) {
      int y = it.first, x = it.second;
      sea[y][x] = max(0, sea[y][x] - melt[y][x]);

      if (sea[y][x] > 0) {
        new_ice.push_back({y, x});
      }
    }

    ice = new_ice;
    ret++;
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}