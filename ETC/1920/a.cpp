#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int n, a[504][504], dp[504][504];

void init() {
  memset(dp, 0, sizeof(dp));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> a[i][j];
    }
  }
  dp[1][1] = a[1][1];
}

int solve() {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
    }
  }

  int ret = -1;
  for (int i = 1; i <= n; i++) {
    ret = max(ret, dp[n][i]);
  }
  return ret;
}

int main() {
  fastIO;
  init();
  cout << solve() << "\n";
}