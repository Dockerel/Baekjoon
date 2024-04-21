#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, w, h, a[54][54], v[54][54], ret, y, x;
queue<pair<int, int>> q;
void init() {
  cin >> w >> h;
  if (!w && !h) exit(0);
  memset(a, 0, sizeof(a));
  memset(v, 0, sizeof(v));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  ret = 0;
  return;
}
void go() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (!v[i][j]) {
        v[i][j] = 1;
        if (a[i][j] == 1) {
          q.push({i, j});
          ret++;
          while (!q.empty()) {
            tie(y, x) = q.front();
            q.pop();
            for (int d = 0; d < 8; d++) {
              int ny = y + "20112200"[d] - '1';
              int nx = x + "11202020"[d] - '1';
              if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
              if (v[ny][nx] || !a[ny][nx]) continue;
              q.push({ny, nx});
              v[ny][nx] = 1;
            }
          }
        }
      }
    }
  }
  cout << ret << "\n";
  return;
}
int main() {
  fastIO;
  while (1) {
    init();
    go();
  }
  return 0;
}