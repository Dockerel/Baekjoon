#include <bits/stdc++.h>
using namespace std;
int n, m, a[10][10], visited[10][10], ret = -1, ny, nx;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
vector<pair<int, int>> wallList, virusList;
void dfs(int y, int x) {
  for (int i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] == 1 ||
        a[ny][nx] == 1)
      continue;
    visited[ny][nx] = 1;
    dfs(ny, nx);
  }
}
int solve() {
  fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
  for (pair<int, int> b : virusList) {
    visited[b.first][b.second] = 1;
    dfs(b.first, b.second);
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0 && visited[i][j] == 0) cnt++;
    }
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 2)
        virusList.push_back({i, j});
      else if (a[i][j] == 0)
        wallList.push_back({i, j});
    }
  }
  for (int i = 0; i < wallList.size(); i++) {
    for (int j = 0; j < i; j++) {
      for (int k = 0; k < j; k++) {
        a[wallList[i].first][wallList[i].second] = 1;
        a[wallList[j].first][wallList[j].second] = 1;
        a[wallList[k].first][wallList[k].second] = 1;
        ret = max(ret, solve());
        a[wallList[i].first][wallList[i].second] = 0;
        a[wallList[j].first][wallList[j].second] = 0;
        a[wallList[k].first][wallList[k].second] = 0;
      }
    }
  }
  cout << ret << "\n";
  return 0;
}