#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

const int INF = 987654321;
int n, ret = INF;
int a[14][14], v[14][14];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  memset(v, 0, sizeof(v));
  return;
}

int setFlower(int y, int x) {
  v[y][x] = 1;
  int _sum = a[y][x];
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    v[ny][nx] = 1;
    _sum += a[ny][nx];
  }
  return _sum;
}

void erase(int y, int x) {
  v[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    v[ny][nx] = 0;
  }
  return;
}

bool intersect(int y, int x) {
  if (v[y][x] == 1) return true;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx]) return true;
  }
  return false;
}

void go(int cnt, int cost) {
  if (cnt == 3) {
    ret = min(ret, cost);
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (intersect(i, j)) continue;
      go(cnt + 1, cost + setFlower(i, j));
      erase(i, j);
    }
  }
}

int main() {
  fastIO;
  init();
  go(0, 0);
  cout << ret << "\n";
  return 0;
}