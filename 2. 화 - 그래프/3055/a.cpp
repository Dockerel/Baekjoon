#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int r, c;
char a[54][54];

int v[54][54];

queue<pii> hog;
queue<pii> water;

pii house;

int iter_size;
int y, x;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        hog.push({i, j});
        v[i][j] = 1;
        continue;
      }
      if (a[i][j] == '*') {
        water.push({i, j});
        v[i][j] = 1;
        continue;
      }
      if (a[i][j] == 'D') {
        house = {i, j};
        continue;
      }
    }
  }
}

void go() {
  // 1. 물을 흘려보내고
  // 2. 고슴도치 이동
  int ret = 0;
  while (1) {
    ret++;
    iter_size = water.size();
    for (int i = 0; i < iter_size; i++) {
      tie(y, x) = water.front();
      water.pop();
      for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || v[ny][nx] ||
            a[ny][nx] == 'X' || a[ny][nx] == 'D')
          continue;
        v[ny][nx] = 1;
        water.push({ny, nx});
      }
    }

    iter_size = hog.size();
    if (hog.size() == 0) {
      break;
    }

    for (int i = 0; i < iter_size; i++) {
      tie(y, x) = hog.front();
      hog.pop();
      for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || v[ny][nx] ||
            a[ny][nx] == 'X')
          continue;
        v[ny][nx] = 1;
        if (ny == house.first && nx == house.second) {
          cout << ret << "\n";
          exit(0);
        }
        hog.push({ny, nx});
      }
    }
  }
  cout << "KAKTUS\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}
