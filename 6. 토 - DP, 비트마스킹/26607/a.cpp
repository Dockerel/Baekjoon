#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, k, x, a, b;

int dp[84][84]
      [16004];  // dp[n][k][x * k] : n번째 사람까지 탐색, k명을 선택, 힘 수치의
                // 총합이 x * k일 때의 스피드 수치의 총합의 최댓값

void init() {
  cin >> n >> k >> x;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l <= x * k; l++) {
        dp[i][j][l] = -1;
      }
    }
    dp[i][0][0] = 0;
  }
}

void go() {
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    for (int j = i; j >= 1; j--) {
      for (int l = 0; l <= x * k; l++) {
        if (dp[i - 1][j - 1][l] == -1) continue;
        dp[i][j - 1][l] = max(dp[i][j - 1][l], dp[i - 1][j - 1][l]);
        if (l + a <= k * x) {
          dp[i][j][l + a] = max(dp[i][j][l + a], dp[i - 1][j - 1][l] + b);
        }
      }
    }
  }

  int ret = 0;
  for (int i = 0; i <= x * k; i++) {
    if (dp[n][k][i] >= 0) {
      int temp = x * k - i;
      ret = max(ret, i * temp);
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