#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tiii tuple<int, int, int>
#define INF 987654321

using namespace std;

int n, m, cctv;
vector<tiii> cctvs;
vector<int> st;

int y, x, type, ret;
// 상하좌우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int a[8][8];  // 씨씨티비와 벽 표시용
int v[8][8];  // 볼 수 있는 영역 표시요

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> cctv;
      if (cctv > 0) {
        if (cctv != 6) {
          cctvs.push_back({i, j, cctv});
          a[i][j] = 2;  // cctv는 2
          continue;
        }
        a[i][j] = 1;  // 벽은 1
      }
    }
  }
  ret = INF;
}

void pointCheck(int y, int x, int idx) {
  while (1) {
    y += dy[idx];
    x += dx[idx];

    if (y < 0 || y >= n || x < 0 || x >= m || a[y][x] == 1) break;
    if (a[y][x] == 2) continue;
    v[y][x] = 1;
  }
}

void display(int y, int x, int cctvType, int dir) {
  switch (cctvType) {
    case 1:
      if (dir == 0) {
        pointCheck(y, x, 2);
      } else if (dir == 1) {
        pointCheck(y, x, 1);
      } else if (dir == 2) {
        pointCheck(y, x, 3);
      } else {
        pointCheck(y, x, 0);
      }
      break;
    case 2:
      if (dir == 0) {
        pointCheck(y, x, 2);
        pointCheck(y, x, 3);
      } else {
        pointCheck(y, x, 0);
        pointCheck(y, x, 1);
      }
      break;
    case 3:
      if (dir == 0) {
        pointCheck(y, x, 0);
        pointCheck(y, x, 3);
      } else if (dir == 1) {
        pointCheck(y, x, 3);
        pointCheck(y, x, 1);
      } else if (dir == 2) {
        pointCheck(y, x, 1);
        pointCheck(y, x, 2);
      } else {
        pointCheck(y, x, 2);
        pointCheck(y, x, 0);
      }
      break;
    case 4:
      if (dir == 0) {
        pointCheck(y, x, 0);
        pointCheck(y, x, 2);
        pointCheck(y, x, 3);
      } else if (dir == 1) {
        pointCheck(y, x, 0);
        pointCheck(y, x, 1);
        pointCheck(y, x, 3);
      } else if (dir == 2) {
        pointCheck(y, x, 1);
        pointCheck(y, x, 2);
        pointCheck(y, x, 3);
      } else {
        pointCheck(y, x, 0);
        pointCheck(y, x, 1);
        pointCheck(y, x, 2);
      }
      break;
    case 5:
      pointCheck(y, x, 0);
      pointCheck(y, x, 1);
      pointCheck(y, x, 2);
      pointCheck(y, x, 3);
      break;
    default:
      break;
  }
}

int cal() {
  int temp = 0;
  memset(v, 0, sizeof(v));
  for (int i = 0; i < st.size(); i++) {
    tie(y, x, type) = cctvs[i];
    display(y, x, type, st[i]);
    v[y][x] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      // 사각지대면서 벽이 아니라면?
      if (v[i][j] == 0 && a[i][j] == 0) temp += 1;
    }
  }

  return temp;
}

void go(int idx) {
  if (idx == cctvs.size()) {
    ret = min(ret, cal());
    return;
  }

  tie(y, x, type) = cctvs[idx];
  switch (type) {
    case 1:
    case 3:
    case 4:
      for (int i = 0; i < 4; i++) {
        st.push_back(i);
        go(idx + 1);
        st.pop_back();
      }
      break;
    case 2:
      for (int i = 0; i < 2; i++) {
        st.push_back(i);
        go(idx + 1);
        st.pop_back();
      }
      break;
    case 5:
      st.push_back(0);
      go(idx + 1);
      st.pop_back();
      break;
    default:
      break;
  }
}

int main() {
  fastIO;
  init();
  go(0);
  cout << ret << "\n";
  return 0;
}