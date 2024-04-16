#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m, a[1004][1004], v[1004][1004], ret[1004][1004], y, x, d;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
pair<int, int> start;
queue<pair<int, int>> q, tempQ;
void swapq(queue<pair<int, int>> &tempQ) {
  queue<pair<int, int>> empty;
  swap(tempQ, empty);
  return;
}
void init() {
  memset(v, 0, sizeof(v));
  memset(ret, -1, sizeof(ret));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) ret[i][j] = 0;
      if (a[i][j] == 2) start = {i, j};
    }
  }
  d = 1;
  q.push(start);
  v[start.first][start.second] = 1;
  ret[start.first][start.second] = 0;
  return;
}
void go() {
  // logic
  while (1) {
    while (!q.empty()) {
      tie(y, x) = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] ||
            a[ny][nx] == 0)
          continue;
        v[ny][nx] = 1;
        ret[ny][nx] = d;
        tempQ.push({ny, nx});
      }
    }
    if (tempQ.empty()) break;
    d++;
    q = tempQ;
    swapq(tempQ);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ret[i][j] << " ";
    }
    cout << "\n";
  }
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}