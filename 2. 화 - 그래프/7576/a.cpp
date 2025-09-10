#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int m, n, num, y, x, ret = 0;
int a[1004][1004], v[1004][1004];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, int>> Q, tempQ;

void swap_queue(queue<pair<int, int>> &q) {
  queue<pair<int, int>> empty;
  swap(q, empty);
}

void init() {
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> num;
      a[i][j] = num;
      if (a[i][j] == 1) {
        Q.push({i, j});
        v[i][j] = 1;
      }
    }
  }
  memset(v, 0, sizeof(v));
  return;
}

void go() {
  while (1) {
    while (!Q.empty()) {
      tie(y, x) = Q.front();
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] == 1) continue;
        if (a[ny][nx] == 0) {
          tempQ.push({ny, nx});
          v[ny][nx] = 1;
        }
      }
    }
    if (tempQ.empty()) break;
    Q = tempQ;
    swap_queue(tempQ);
    ret++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0 && v[i][j] == 0) {
        cout << "-1\n";
        return;
      }
    }
  }

  cout << ret << "\n";
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}