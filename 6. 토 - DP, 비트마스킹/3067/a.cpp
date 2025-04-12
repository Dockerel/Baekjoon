#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, n, coin, m;
vector<int> coins;
int dp[24][10004];

void init() { cin >> t; }

void go() {
  coins.clear();
  coins.push_back(0);
  memset(dp, 0, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> coin;
    coins.push_back(coin);
  }
  cin >> m;

  for (int i = 1; i <= n; i++) {
    auto it = coins[i];
    dp[i][0] = 1;
    for (int j = 1; j <= m; j++) {
      if (j - it < 0) {
        dp[i][j] = dp[i - 1][j];
        continue;
      }
      dp[i][j] = dp[i - 1][j] + dp[i][j - it];
    }
  }

  cout << dp[n][m] << "\n";
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < t; _++) {
    go();
  }
  return 0;
}