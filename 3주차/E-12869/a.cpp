#include <bits/stdc++.h>
using namespace std;
int n, ret = 0;
int dmg[3] = {9, 3, 1};
int h[3];

void Input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
}

void Solution() {
  // bfs 느낌으로 싹 돌리기
}

void Solve() {
  Input();
  Solution();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
  return 0;
}