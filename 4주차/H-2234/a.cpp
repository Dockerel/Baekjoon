#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, w, rooms, area, max_area, max_sum_area, seq;
int a[54][54][4];
int visited[54][54];
pair<int, int> areas[54][54];
queue<pair<int, int>> same_rooms;

// 서->북->동->남
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

void init() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> w;
      // 2진수로 바꿔서 -> 남동북서 (서->북->동->남)
      for (int k = 0; k < 4; k++) {
        if (w & (1 << k)) {
          a[i][j][k] = 1;
        } else {
          a[i][j][k] = 0;
        }
      }
    }
  }
  max_area = max_sum_area = -1;
  seq = rooms = 0;
}

void dfs(int y, int x) {
  visited[y][x] = 1;
  area++;
  same_rooms.push({y, x});
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
    if (a[y][x][i] || visited[ny][nx]) continue;

    dfs(ny, nx);
  }
}

void findMaxSum(int y, int x, int d) {
  int ny = y + dy[d];
  int nx = x + dx[d];

  if (ny < 0 || ny >= m || nx < 0 || nx >= n) return;
  if (areas[y][x].first != areas[ny][nx].first) {
    max_sum_area = max(max_sum_area, areas[y][x].second + areas[ny][nx].second);
  }
}

void go() {
  // 1. 이 성에 있는 방의 개수 -> dfs
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[i][j]) {
        area = 0;
        dfs(i, j);
        rooms++;

        // areas에 area 값 업데이트
        seq++;
        while (!same_rooms.empty()) {
          int y, x;
          tie(y, x) = same_rooms.front();
          same_rooms.pop();
          areas[y][x] = {seq, area};
        }

        max_area = max(max_area, area);
      }
    }
  }
  cout << rooms << "\n";

  // 2. 가장 넓은 방의 넓이 -> dfs + max값 업데이트
  cout << max_area << "\n";

  // 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
  // 가장자리 벽은 제거 불가
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < 4; k++) {
        findMaxSum(i, j, k);
      }
    }
  }
  cout << max_sum_area << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}