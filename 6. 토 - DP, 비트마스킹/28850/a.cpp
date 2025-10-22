#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  const int INF = INT_MAX / 2;

  // dp[i][j]: 총 i 보너스, 연속 접속 j일 때 최소 일수 (j=0 연속 접속 안함, 다음
  // 접속은 a_1로 시작)
  vector<vector<int>> dp(x + 1, vector<int>(n + 1, INF));
  dp[0][0] = 0;

  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= n; j++) {
      if (dp[i][j] == INF) continue;

      // 1) 계속 연속 접속하는 경우: 연속 접속 일수 j+1 (최대 n)
      int next_j = min(j + 1, n);
      int bonus = a[next_j - 1];  // 인덱스 맞추기 위해 -1
      if (i + bonus <= x) {
        dp[i + bonus][next_j] = min(dp[i + bonus][next_j], dp[i][j] + 1);
      }

      // 2) 하루 건너뛰고 다시 a_1부터 시작하는 경우
      // 현재 연속 접속을 끊고, 1일 쉬고 다음 날 다시 시작: 2일 소요 (쉬는 날 +
      // 접속하는 날)
      bonus = a[0];
      if (i + bonus <= x) {
        dp[i + bonus][1] = min(dp[i + bonus][1], dp[i][j] + 2);
      }
    }
  }

  int answer = INF;
  for (int j = 0; j <= n; j++) {
    answer = min(answer, dp[x][j]);
  }
  if (answer == INF)
    cout << -1 << "\n";
  else
    cout << answer << "\n";

  return 0;
}