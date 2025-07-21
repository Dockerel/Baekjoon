#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
int a[1004][1004];
int dp[1004][1004];
int dy[3] = {1, 0, 1};
int dx[3] = {0, 1, 1};

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][0] = a[0][0];
}

void go() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0) continue;
      int up = i - 1 >= 0 ? dp[i - 1][j] + a[i][j] : 0;
      int left = j - 1 >= 0 ? dp[i][j - 1] + a[i][j] : 0;
      int leftup = i - 1 >= 0 && j - 1 >= 0 ? dp[i - 1][j - 1] + a[i][j] : 0;
      dp[i][j] = max({up, left, leftup});
    }
  }
  cout << dp[n - 1][m - 1] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}