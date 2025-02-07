#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

int n;
int a[1004][3];
int dp[1004][3];
int ret;

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  ret = INF;
}

void go() {
  // 결국 1번집하고 N번집하고 다르고 나머지는 자기 앞뒤 집과 달라야 함?
  // -> 자기 앞집하고 다르고 N번집은 1번집과도 달라야 함

  for (int k = 0; k < 3; k++) {
    for (int i = 1; i <= n; i++) {
      dp[i][0] = dp[i][1] = dp[i][2] = INF;
    }

    // 첫 집을 고정
    dp[1][k] = a[1][k];

    for (int i = 2; i <= n; i++) {
      dp[i][0] = a[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = a[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = a[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    for (int c = 0; c < 3; c++) {
      if (k != c) ret = min(ret, dp[n][c]);
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