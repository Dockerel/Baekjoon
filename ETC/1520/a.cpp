#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int m, n;
int a[504][504];
int dp[504][504];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void init() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
}

int solve(int y, int x) {
  if (y == m - 1 && x == n - 1) return 1;
  if (dp[y][x] != -1) return dp[y][x];

  dp[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;

    if (a[y][x] > a[ny][nx]) {
      dp[y][x] += solve(ny, nx);
    }
  }

  return dp[y][x];
}

int main() {
  fastio;

  init();
  cout << solve(0, 0) << "\n";

  return 0;
}