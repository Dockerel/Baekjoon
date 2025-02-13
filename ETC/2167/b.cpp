#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, k, yy, x1, y2, x2, ret;
int a[304][304], dp[304][304];

void init() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = dp[i][j] = 0;
      cin >> a[i][j];
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
    }
  }
}

void go() {
  cin >> k;
  for (int _ = 0; _ < k; _++) {
    cin >> yy >> x1 >> y2 >> x2;
    cout << dp[y2][x2] - dp[y2][x1 - 1] - dp[yy - 1][x2] + dp[yy - 1][x1 - 1]
         << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}