#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, a[29][29], v[29][29], y, x;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
string s;
queue<pair<int, int>> q;
vector<int> ret;
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j] - '0';
    }
  }
  memset(v, 0, sizeof(v));
  return;
}
void go() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 1 && v[i][j] == 0) {
        int temp = 1;
        v[i][j] = 1;
        q.push({i, j});
        while (!q.empty()) {
          tie(y, x) = q.front();
          q.pop();
          for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n || v[ny][nx] ||
                a[ny][nx] == 0)
              continue;
            v[ny][nx] = 1;
            temp += 1;
            q.push({ny, nx});
          }
        }
        ret.push_back(temp);
      }
    }
  }
  sort(ret.begin(), ret.end());
  cout << ret.size() << "\n";
  for (auto it : ret) {
    cout << it << "\n";
  }
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}