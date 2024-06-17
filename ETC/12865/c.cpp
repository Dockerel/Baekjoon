#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, k;
int dp[100004][104], wgt[104], val[104];

void init() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> wgt[i] >> val[i];
  }
  memset(dp, 0, sizeof(dp));
  return;
}

int go() {
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j - 1];
      if (wgt[j] <= i) {
        dp[i][j] = max(dp[i][j], dp[i - wgt[j]][j - 1] + val[j]);
      }
    }
  }
  return dp[k][n];
}

int main() {
  fastio;

  init();
  cout << go() << "\n";

  return 0;
}