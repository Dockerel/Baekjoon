#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int n, t, d, m, bulgum, max_bumgum;

int dp[1004];  // 세이브 가능한 벌금 합 (최대)

void init() {
  cin >> n >> t;
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
}

void go() {
  for (int _ = 0; _ < n; _++) {
    cin >> d >> m;  // d의 합이 t 이하 면서 m이 최대가 되게
    bulgum += m;
    for (int i = t; i >= d; i--) {
      if (dp[i - d] >= 0) {
        dp[i] = max(dp[i], dp[i - d] + m);
      }
    }
  }
  for (int i = 0; i <= t; i++) {
    max_bumgum = max(max_bumgum, dp[i]);
  }
  cout << bulgum - max_bumgum << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}