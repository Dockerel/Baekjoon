#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int a[9][9];
string s;
vector<pii> v;

void init() {
  for (int i = 0; i < 9; i++) {
    cin >> s;
    for (int j = 0; j < 9; j++) {
      a[i][j] = s[j] - '0';
      if (a[i][j] == 0) {
        v.push_back({i, j});
      }
    }
  }
}

int isPossible(int y, int x, int num) {
  // 가로
  for (int i = 0; i < 9; i++) {
    if (a[y][i] == num) return 0;
  }

  // 세로
  for (int i = 0; i < 9; i++) {
    if (a[i][x] == num) return 0;
  }

  // 해당 칸 안에서 검사
  // 012 345 678
  int sy = (y / 3) * 3;
  int sx = (x / 3) * 3;
  for (int i = sy; i < sy + 3; i++) {
    for (int j = sx; j < sx + 3; j++) {
      if (a[i][j] == num) return 0;
    }
  }

  return 1;
}

void go(int idx) {
  if (idx == v.size()) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
    exit(0);
  }

  int y, x;
  tie(y, x) = v[idx];
  for (int i = 1; i <= 9; i++) {
    // 해당 위치에 i를 넣을 수 있는지
    if (isPossible(y, x, i)) {
      a[y][x] = i;
      go(idx + 1);
      a[y][x] = 0;
    }
  }
  return;
}

int main() {
  fastIO;
  init();
  go(0);
  return 0;
}