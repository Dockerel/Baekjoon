#include <bits/stdc++.h>
using namespace std;

int n, m, x1, yy1, x2, y2, ny, nx, ret = 0;
char a[304][304];
int v[304][304];
string s;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

void go(int y, int x) {
  queue<pair<int, int>> Q;
  vector<pair<int, int>> human;

  human.push_back({y, x});
  v[y][x] = 1;

  while (1) {
    ret++;

    for (pair<int, int> h : human) Q.push(h);
    human.clear();

    while (!Q.empty()) {
      tie(y, x) = Q.front();
      Q.pop();

      for (int i = 0; i < 4; i++) {
        ny = dy[i] + y;
        nx = dx[i] + x;

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        if (v[ny][nx] == 1) continue;

        if (a[ny][nx] == '0') {
          Q.push({ny, nx});
          v[ny][nx] = 1;
        } else if (a[ny][nx] == '1') {
          human.push_back({ny, nx});
          v[ny][nx] = 1;
        } else if (a[ny][nx] == '#') {
          cout << ret << "\n";
          exit(0);
        }
      }
    }
  }
  return;
}

int main() {
  fastIO();
  cin >> n >> m;
  cin >> x1 >> yy1 >> x2 >> y2;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];
    }
  }
  go(x1 - 1, yy1 - 1);
  return 0;
}