#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
int a[54][54];
string s;

int visited[54][54];
int dp[54][54];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == 'H') {
        a[i][j] = -1;
      } else {
        a[i][j] = s[j] - '0';
      }
    }
  }
  memset(dp, -1, sizeof(dp));
}

int go(int y, int x) {
  if (y < 0 || y >= n || x < 0 || x >= m || a[y][x] == -1) return 0;
  if (visited[y][x] > 0) {
    cout << "-1\n";
    exit(0);
  }
  if (dp[y][x] != -1) return dp[y][x];

  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i] * a[y][x];
    int nx = x + dx[i] * a[y][x];

    dp[y][x] = max(dp[y][x], go(ny, nx) + 1);
  }
  visited[y][x] = 0;
  return dp[y][x];
}

int main() {
  fastIO;
  init();
  cout << go(0, 0) << "\n";
  return 0;
}