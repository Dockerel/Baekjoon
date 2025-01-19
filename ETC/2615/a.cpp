#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int a[20][20];

void init() {
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      cin >> a[i][j];
    }
  }
}

bool not6mok(int y, int x, int type) {
  switch (type) {
    case 12:
      if (y - 5 > 0 && a[y - 5][x] == a[y][x]) return false;
      if (a[y + 1][x] == a[y][x]) return false;
      break;
    case 1:
      if (y - 5 >= 0 && x + 5 < 19 && a[y - 5][x + 5] == a[y][x]) return false;
      if (a[y + 1][x - 1] == a[y][x]) return false;
      break;
    case 3:
      if (x + 5 < 19 && a[y][x + 5] == a[y][x]) return false;
      if (a[y][x - 1] == a[y][x]) return false;
      break;
    case 4:
      if (y + 5 < 19 && x + 5 < 19 && a[y + 5][x + 5] == a[y][x]) return false;
      if (a[y - 1][x - 1] == a[y][x]) return false;
      break;
    case 6:
      if (y + 5 < 19 && a[y + 5][x] == a[y][x]) return false;
      if (a[y - 1][x] == a[y][x]) return false;
      break;
    case 7:
      if (y + 5 < 19 && x - 5 >= 0 && a[y + 5][x - 5] == a[y][x]) return false;
      if (a[y - 1][x + 1] == a[y][x]) return false;
      break;
    case 9:
      if (x - 5 >= 0 && a[y][x - 5] == a[y][x]) return false;
      if (a[y][x + 1] == a[y][x]) return false;
      break;
    case 10:
      if (y - 5 >= 0 && x - 5 >= 0 && a[y - 5][x - 5] == a[y][x]) return false;
      if (a[y + 1][x + 1] == a[y][x]) return false;
      break;
    default:
      break;
  }
  return true;
}

void go() {
  for (int i = 0; i < 19; i++) {
    for (int j = 0; j < 19; j++) {
      // 12
      if (i - 4 >= 0) {
        if (a[i][j] && a[i][j] == a[i - 1][j] && a[i][j] == a[i - 2][j] &&
            a[i][j] == a[i - 3][j] && a[i][j] == a[i - 4][j]) {
          if (not6mok(i, j, 12)) {
            cout << a[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
            return;
          }
        }
      }
      // 1.5
      if (i - 4 >= 0 && j + 4 < 19) {
        if (a[i][j] && a[i][j] && a[i][j] == a[i - 1][j + 1] &&
            a[i][j] == a[i - 2][j + 2] && a[i][j] == a[i - 3][j + 3] &&
            a[i][j] == a[i - 4][j + 4]) {
          if (not6mok(i, j, 1)) {
            cout << a[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
            return;
          }
        }
      }
      // 3
      if (j + 4 < 19) {
        if (a[i][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] &&
            a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4]) {
          if (not6mok(i, j, 3)) {
            cout << a[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
            return;
          }
        }
      }
      // 4.5
      if (i + 4 < 19 && j + 4 < 19) {
        if (a[i][j] && a[i][j] == a[i + 1][j + 1] &&
            a[i][j] == a[i + 2][j + 2] && a[i][j] == a[i + 3][j + 3] &&
            a[i][j] == a[i + 4][j + 4]) {
          if (not6mok(i, j, 4)) {
            cout << a[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
            return;
          }
        }
      }
      // 6
      if (i + 4 < 19) {
        if (a[i][j] && a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] &&
            a[i][j] == a[i + 3][j] && a[i][j] == a[i + 4][j]) {
          if (not6mok(i, j, 6)) {
            cout << a[i][j] << "\n" << i + 1 << " " << j + 1 << "\n";
            return;
          }
        }
      }
      // 7.5
      if (i + 4 < 19 && j - 4 >= 0) {
        if (a[i][j] && a[i][j] == a[i + 1][j - 1] &&
            a[i][j] == a[i + 2][j - 2] && a[i][j] == a[i + 3][j - 3] &&
            a[i][j] == a[i + 4][j - 4]) {
          if (not6mok(i, j, 7)) {
            cout << a[i + 4][j - 4] << "\n"
                 << i + 4 + 1 << " " << j - 4 + 1 << "\n";
            return;
          }
        }
      }
      // 9
      if (j - 4 < 19) {
        if (a[i][j] && a[i][j] == a[i][j - 1] && a[i][j] == a[i][j - 2] &&
            a[i][j] == a[i][j - 3] && a[i][j] == a[i][j - 4]) {
          if (not6mok(i, j, 9)) {
            cout << a[i][j - 4] << "\n" << i + 1 << " " << j - 4 + 1 << "\n";
            return;
          }
        }
      }
      // 10.5
      if (i - 4 >= 0 && j - 4 >= 0) {
        if (a[i][j] && a[i][j] == a[i - 1][j - 1] &&
            a[i][j] == a[i - 2][j - 2] && a[i][j] == a[i - 3][j - 3] &&
            a[i][j] == a[i - 4][j - 4]) {
          if (not6mok(i, j, 10)) {
            cout << a[i - 4][j - 4] << "\n"
                 << i - 4 + 1 << " " << j - 4 + 1 << "\n";
            return;
          }
        }
      }
    }
  }
  cout << "0\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}
