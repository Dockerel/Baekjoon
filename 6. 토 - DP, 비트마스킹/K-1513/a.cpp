#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MOD 1000007

using namespace std;

int n, m, c;
int n1, n2;
int a[54][54];

int dp[54][54][54][54];  // y,x,최근에 방문한 오락실 번호,지난 오락실 수

void init() {
  cin >> n >> m >> c;
  dp[1][1][0][0] = 1;
  for (int i = 1; i <= c; i++) {
    cin >> n1 >> n2;
    if (n1 == 1 && n2 == 1) {
      dp[1][1][0][0] = 0;
      dp[1][1][i][1] = 1;
    }
    a[n1][n2] = i;
  }
}

void go() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // 이미 (1,1)은 처리함
      if (i == 1 && j == 1) continue;

      if (a[i][j] > 0) {
        for (int l = 0; l <= a[i][j]; l++) {
          for (int k = 0; k <= l; k++) {
            dp[i][j][a[i][j]][k + 1] +=
                (dp[i - 1][j][l][k] + dp[i][j - 1][l][k]) % MOD;
          }
        }
      } else {
        for (int l = 0; l <= c; l++) {
          for (int k = 0; k <= l; k++) {
            dp[i][j][l][k] += (dp[i - 1][j][l][k] + dp[i][j - 1][l][k]) % MOD;
          }
        }
      }
    }
  }

  for (int i = 0; i <= c; i++) {
    int ret = 0;
    for (int j = 0; j <= c; j++) {
      ret += (dp[n][m][j][i] % MOD);
    }
    cout << ret % MOD << " ";
  }
  cout << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}