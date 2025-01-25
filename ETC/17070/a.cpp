#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tiii tuple<int, int, int>
#define pii pair<int, int>

using namespace std;

int n, y, x, d, ret;
int a[18][18];

int dy[3] = {0, 1, 1};
int dx[3] = {1, 1, 0};

queue<tiii> q;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  if (a[n - 1][n - 1]) {
    cout << "0\n";
    exit(0);
  }

  ret = 0;
}

void move(int currY, int currX, int currD, int nextD) {
  int ny = currY + dy[nextD];
  int nx = currX + dx[nextD];
  if (ny >= n || nx >= n || a[ny][nx]) return;
  if (nextD == 1 && (a[ny - 1][nx] || a[ny][nx - 1])) return;
  q.push({ny, nx, nextD});
}

void go() {
  // y, x, dir
  // dir : 0, 45, 90
  q.push({0, 1, 0});

  while (!q.empty()) {
    tie(y, x, d) = q.front();
    q.pop();

    if (y == n - 1 && x == n - 1) {
      ret += 1;
      continue;
    }

    if (d == 0) {
      for (int i = 0; i < 3; i++) {
        if (i == 2) continue;
        move(y, x, d, i);
      }
    } else if (d == 1) {
      for (int i = 0; i < 3; i++) {
        move(y, x, d, i);
      }
    } else {
      for (int i = 0; i < 3; i++) {
        if (i == 0) continue;
        move(y, x, d, i);
      }
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