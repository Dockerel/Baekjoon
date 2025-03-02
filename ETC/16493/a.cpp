#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, d,
    p;  // 남은 기간, 챕터의 수, 챕터 당 읽는데 소요되는 일 수, 페이지 수
// [남은 기간] 동안 최대의 [페이지 수] 구하기

int dp[24][204];
// dp[i][j] : i번째 챕터까지 확인했을 때 j일의 남은 기간이 있을 때 읽을 수 있는
// 최대 페이지 수

void init() { cin >> n >> m; }

void go() {
  for (int i = 1; i <= m; i++) {
    cin >> d >> p;
    for (int j = 0; j <= n; j++) {
      if (j - d < 0)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - d] + p);
    }
  }

  int ret = -1;
  for (int i = 0; i <= n; i++) {
    ret = max(ret, dp[m][i]);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}