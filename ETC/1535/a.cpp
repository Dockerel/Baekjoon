#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int a[24], b[24];
int dp[24][104][2004];

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  memset(dp, 0, sizeof(dp));
  dp[0][100][0] = 1;
}

int go() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; k <= n * 100; k++) {
        if (dp[i - 1][j][k] == 1) {
          if (j - a[i] > 0) dp[i][j - a[i]][k + b[i]] = 1;
          dp[i][j][k] = 1;
        }
      }
    }
  }

  int ret = 0;
  for (int i = n; i >= 1; i--) {
    for (int j = 100; j >= 0; j--) {
      for (int k = n * 100; k >= 0; k--) {
        if (dp[i][j][k] == 1) ret = max(ret, k);
      }
    }
  }
  return ret;
}

int main() {
  fastio;

  init();
  cout << go() << "\n";

  return 0;
}