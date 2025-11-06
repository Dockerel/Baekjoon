#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int a[14][14];
int papers[8];
int ret;

void init() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= 5; i++) {
    papers[i] = 5;
  }

  ret = 987654321;
}

void go(int y, int x) {
  if (y == 10 && x == 0) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (a[i][j] == 1) {
          return;
        }
      }
    }
    int temp = 0;
    for (int i = 1; i <= 5; i++) {
      temp += papers[i];
    }
    ret = min(ret, 25 - temp);
    return;
  }
  if (a[y][x] == 1) {
    for (int k = 5; k > 0; k--) {
      // 붙힐 수 있는 공간 충분한지 확인
      int ny = y + k - 1;
      int nx = x + k - 1;
      if (ny >= 10 || nx >= 10) continue;
      // 붙힐 수 있는지 확인
      int flag = 1;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          if (a[y + i][x + j] == 0) flag = 0;
        }
      }
      // 현재 크기로는 못 붙힘
      if (!flag || papers[k] == 0) continue;
      // 색종이 붙히기
      papers[k] -= 1;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          a[y + i][x + j] = 0;
        }
      }
      // 다음 좌표 선택
      int nextY = x + 1 == 10 ? y + 1 : y;
      int nextX = x + 1 == 10 ? 0 : x + 1;
      go(nextY, nextX);
      // 복구
      papers[k] += 1;
      for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
          a[y + i][x + j] = 1;
        }
      }
    }
  } else {
    int nextY = x + 1 == 10 ? y + 1 : y;
    int nextX = x + 1 == 10 ? 0 : x + 1;
    go(nextY, nextX);
  }
}

int main() {
  fastIO;
  init();
  go(0, 0);
  cout << (ret == 987654321 ? -1 : ret) << "\n";
  return 0;
}