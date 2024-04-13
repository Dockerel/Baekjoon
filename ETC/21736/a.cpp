#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
queue<pair<int, int>> q;
int n, m, v[604][604], y, x, ret;
char a[604][604];
string s;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
void init() {
  memset(v, 0, sizeof(v));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];
      if (a[i][j] == 'I') {
        q.push({i, j});
        v[i][j] = 1;
      }
    }
  }
  ret = 0;
  return;
}
void go() {
  while (!q.empty()) {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = dy[i] + y;
      int nx = dx[i] + x;
      if (ny < 0 || ny >= n || nx < 0 || nx >= m || v[ny][nx] ||
          a[ny][nx] == 'X')
        continue;
      if (a[ny][nx] == 'P') ret++;
      v[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
  if (ret == 0)
    cout << "TT\n";
  else
    cout << ret << "\n";
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}