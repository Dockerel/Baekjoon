#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, ret;
int visited[104][104];

int x, y, d, z;
//  x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대이다.
// 0: x좌표가 증가하는 방향 (→)
// 1: y좌표가 감소하는 방향 (↑)
// 2: x좌표가 감소하는 방향 (←)
// 3: y좌표가 증가하는 방향 (↓)

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

vector<int> history;
int historySize;

void init() {
  cin >> n;
  memset(visited, 0, sizeof(visited));
  ret = 0;
}

void drawDragonCurve(int y, int x, int d, int z) {
  history.clear();
  history.push_back(d);

  visited[y][x] = 1;
  y += dy[d], x += dx[d];
  visited[y][x] = 1;

  for (int _ = 1; _ <= z; _++) {
    historySize = history.size();
    for (int i = historySize - 1; i >= 0; i--) {
      int newDir = (history[i] + 1) % 4;
      y += dy[newDir], x += dx[newDir];
      visited[y][x] = 1;
      history.push_back(newDir);
    }
  }
}

void go() {
  for (int _ = 0; _ < n; _++) {
    cin >> x >> y >> d >> z;
    drawDragonCurve(y, x, d, z);
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] &&
          visited[i + 1][j + 1])
        ret += 1;
    }
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}