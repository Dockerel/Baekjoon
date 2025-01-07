#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1004
using namespace std;

int n;
int a[MAX][MAX];
string s;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = (s[j] == '*' ? 1 : 0);
    }
  }
}

void go() {
  // 심장
  int h_flag = 0;
  int h_x, h_y;
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (a[i][j] && a[i - 1][j] && a[i][j - 1] && a[i + 1][j] && a[i][j + 1]) {
        h_x = j;
        h_y = i;
        cout << i + 1 << " " << j + 1 << "\n";
        h_flag = 1;
        break;
      }
    }
    if (h_flag) break;
  }
  // 팔
  for (int i = h_x; i >= 0; i--) {
    if (a[h_y][i] == 0) {
      cout << h_x - i - 1 << " ";
      break;
    }
    if (i == 0) {
      cout << h_x - i << " ";
      break;
    }
  }
  for (int i = h_x; i < n; i++) {
    if (a[h_y][i] == 0) {
      cout << i - h_x - 1 << " ";
      break;
    }
    if (i == n - 1) {
      cout << i - h_x << " ";
      break;
    }
  }
  // 허리
  int b_y;
  for (int i = h_y; i < n; i++) {
    if (a[i][h_x] == 0) {
      cout << i - h_y - 1 << " ";
      b_y = i;
      break;
    }
  }
  // 다리
  for (int i = b_y; i < n; i++) {
    if (a[i][h_x - 1] == 0) {
      cout << i - b_y << " ";
      break;
    }
    if (i == n - 1) {
      cout << i - b_y + 1 << " ";
      break;
    }
  }
  for (int i = b_y; i < n; i++) {
    if (a[i][h_x + 1] == 0) {
      cout << i - b_y << " ";
      break;
    }
    if (i == n - 1) {
      cout << i - b_y + 1 << "\n";
      break;
    }
  }
}

int main() {
  fastIO;
  init();
  go();
}