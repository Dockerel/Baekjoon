#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000000000

using namespace std;

int n;
// 끝 수 기준
long long dp[104][10];

void init() {
  cin >> n;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < 10; i++) {
    dp[1][i] = 1;
  }
}

void go() {
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0) {
        dp[i][j] = dp[i - 1][1];
      } else if (j == 9) {
        dp[i][j] = dp[i - 1][8];
      } else {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
      }
      dp[i][j] %= MAX;
    }
  }

  int ret = 0;
  for (int i = 0; i < 10; i++) {
    ret = (ret + dp[n][i]) % MAX;
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}