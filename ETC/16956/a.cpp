#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int r, c, flag;
char a[504][504];
string s;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> wolves;
void init() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      a[i][j] = s[j];
      if (s[j] == 'W') {
        wolves.push_back({i, j});
      }
    }
  }
}
void go() {
  for (auto it : wolves) {
    if (flag) break;
    for (int i = 0; i < 4; i++) {
      int ny = it.first + dy[i];
      int nx = it.second + dx[i];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
      if (a[ny][nx] == 'S') {
        flag = 1;
        break;
      }
    }
  }
  if (flag) {
    cout << "0\n";
    return;
  }
  cout << "1\n";
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] == '.') {
        cout << 'D';
      } else {
        cout << a[i][j];
      }
    }
    cout << "\n";
  }
  return;
}
int main() {
  fastIO;
  init();
  go();
}