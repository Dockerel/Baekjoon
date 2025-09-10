#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, b, w;
int paper[130][130];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> paper[i][j];
    }
  }
  b = w = 0;
}

int check(int x, int y, int len) {
  for (int i = y; i < y + len; i++) {
    for (int j = x; j < x + len; j++) {
      if (paper[i][j] != paper[y][x]) return 2;  // should be devided
    }
  }
  return paper[y][x];  // b: 1, w: 0
}

void go(int x, int y, int len) {
  if (len == 1 || check(x, y, len) < 2) {
    paper[y][x] == 1 ? b++ : w++;
    return;
  }
  go(x, y, len / 2);
  go(x + len / 2, y, len / 2);
  go(x, y + len / 2, len / 2);
  go(x + len / 2, y + len / 2, len / 2);
}

int main() {
  fastIO;
  init();
  go(0, 0, n);
  cout << w << "\n" << b << "\n";
  return 0;
}