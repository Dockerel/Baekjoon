#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int m, n;
int a[1004][1004];
int dp[1004][1004];

void init() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
}

void go() {
  int ret = -1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] > 0) continue;
      dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
      ret = max(ret, dp[i][j]);
    }
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}