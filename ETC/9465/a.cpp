#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, n;
int a[2][100004];
int dp[3][100004];

void init() { cin >> t; }

void go() {
  // 0 : 0번 자리 선택, 1 : 1번 자리 선택, 2 : 선택 x
  dp[0][0] = a[0][0];
  dp[1][0] = a[1][0];
  dp[2][0] = 0;
  for (int i = 1; i < n; i++) {
    // 0번 자리
    dp[0][i] = max(dp[1][i - 1] + a[0][i], dp[2][i - 1] + a[0][i]);
    // 1번 자리
    dp[1][i] = max(dp[0][i - 1] + a[1][i], dp[2][i - 1] + a[1][i]);
    // 선택 x
    dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);
  }
  cout << max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]) << "\n";
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < t; _++) {
    cin >> n;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    memset(dp, 0, sizeof(dp));
    go();
  }
  return 0;
}