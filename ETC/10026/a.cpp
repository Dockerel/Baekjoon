#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, y, x, ret1, ret2;
char a[104][104];
int v[104][104];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init() {
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j];
    }
  }
}

int type(char prev, char color, int blind) {
  if (prev == color)
    return 1;
  else if (blind && prev != 'B' && color != 'B')
    return 1;
  else
    return 0;
}

void go(int blind) {
  memset(v, 0, sizeof(v));
  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j] == 0) {
        q.push({i, j});
        v[i][j] = 1;
        while (!q.empty()) {
          tie(y, x) = q.front();
          q.pop();
          for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx] == 1)
              continue;
            if (!type(a[i][j], a[ny][nx], blind)) continue;
            q.push({ny, nx});
            v[ny][nx] = 1;
          }
        }
        blind == 1 ? ret2 += 1 : ret1 += 1;
      }
    }
  }
}

int main() {
  fastio;

  init();

  go(0);
  go(1);

  cout << ret1 << " " << ret2 << "\n";

  return 0;
}