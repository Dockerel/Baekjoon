#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, m, cheese, ret;

int y, x;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int a[104][104];
int v[104][104];

queue<pii> q;
queue<pii> c;
queue<pii> melt;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 1) cheese++;
    }
  }
  ret = 0;
}

void go() {
  // 계속 반복 (치즈가 없을 때 까지)
  while (cheese > 0) {
    // 외부 공간 bfs
    memset(v, 0, sizeof(v));
    q.push({0, 0});
    v[0][0] = 1;
    while (!q.empty()) {
      tie(y, x) = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] == 1) continue;
        if (a[ny][nx] == 1) {
          c.push({ny, nx});  // 공기와 닿아있는 치즈
          v[ny][nx] = 1;
          continue;
        }
        q.push({ny, nx});
        v[ny][nx] = 1;
      }
    }

    // 공기와 접촉해 있는 치즈 확인
    while (!c.empty()) {
      tie(y, x) = c.front();
      c.pop();
      int air = 0;
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (a[ny][nx] == 0 && v[ny][nx] == 1) air++;
      }
      if (air >= 2) {  // 치즈가 녹는 경우
        melt.push({y, x});
        cheese--;
      }
    }

    while (!melt.empty()) {
      tie(y, x) = melt.front();
      melt.pop();
      a[y][x] = 0;
    }

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