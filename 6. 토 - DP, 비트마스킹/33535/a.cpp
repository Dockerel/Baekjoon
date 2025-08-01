#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, p, h;
int dp[10004];

void init() {
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
}

void go() {
  for (int _ = 0; _ < n; _++) {
    cin >> p >> h;
    for (int i = m; i >= p; i--) {
      if (dp[i - p] >= 0) {
        dp[i] = max(dp[i], dp[i - p] + h);
      }
    }
  }

  int ret = -1;
  for (int i = 0; i <= m; i++) {
    ret = max(ret, dp[i]);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}