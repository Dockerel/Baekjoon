#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
int a[2004];
int m;
int s, e;

int dp[2004][2004];

void init() {
  memset(dp, 0, sizeof(dp));

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = 1;
  }
}

void go() {
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == a[i + 1]) {
      dp[i][i + 1] = 1;
    }
  }

  for (int i = 1; i <= n - 2; i++) {
    if (a[i] == a[i + 2]) {
      dp[i][i + 2] = 1;
    }
  }

  for (int i = n - 3; i >= 1; i--) {
    for (int j = i + 3; j <= n; j++) {
      if (a[i] == a[j] && dp[i + 1][j - 1]) {
        dp[i][j] = 1;
      }
    }
  }
}

int main() {
  fastIO;
  init();
  go();

  cin >> m;
  for (int _ = 0; _ < m; _++) {
    cin >> s >> e;
    cout << dp[s][e] << "\n";
  }

  return 0;
}