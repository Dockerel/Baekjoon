#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int r, c, k, ret;
char a[6][6];
int visited[6][6];
string s;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init() {
  ret = 0;
  memset(visited, 0, sizeof(visited));
  cin >> r >> c >> k;
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      a[i][j] = s[j];
    }
  }
  visited[r - 1][0] = 1;
}

void go(int y, int x, int cnt) {
  if (cnt == k - 1) {
    if (y == 0 && x == c - 1) ret += 1;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx] ||
        a[ny][nx] == 'T')
      continue;
    visited[ny][nx] = 1;
    go(ny, nx, cnt + 1);
    visited[ny][nx] = 0;
  }
}

int main() {
  fastIO;

  init();
  go(r - 1, 0, 0);

  cout << ret << "\n";

  return 0;
}