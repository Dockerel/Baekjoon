#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int a[9][9];
vector<pii> v;

void init() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        v.push_back({i, j});
      }
    }
  }
}

// currLoc에 넣을 수 있는 숫자 검사
int canPut(int x, pii loc) {
  // 가로, 세로, 해당 9칸
  for (int i = 0; i < 9; i++) {
    if (a[loc.ff][i] == x) {
      return 0;
    }
  }

  for (int i = 0; i < 9; i++) {
    if (a[i][loc.ss] == x) {
      return 0;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[(loc.ff / 3) * 3 + i][(loc.ss / 3) * 3 + j] == x) {
        return 0;
      }
    }
  }

  return 1;
}

void go(int curr) {
  if (curr == v.size()) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << a[i][j] << " ";
      }
      cout << "\n";
    }
    exit(0);
  }

  pii currLoc = v[curr];
  for (int i = 1; i <= 9; i++) {
    if (canPut(i, currLoc)) {
      a[currLoc.ff][currLoc.ss] = i;
      go(curr + 1);
      a[currLoc.ff][currLoc.ss] = 0;
    }
  }
}

int main() {
  fastIO;
  init();
  go(0);
  return 0;
}