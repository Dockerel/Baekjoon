#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int n;
int t[1500004], p[1500004], dp[1500004];

void init() {
  memset(dp, 0, sizeof(dp));
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> p[i];
  }
}

int solve() {  // dp[i] : i번째 날 전날까지 일해서 번 돈의 합
  int ret = 0;
  for (int i = 1; i <= n + 1; i++) {  // n번째 날까지 검사해야 하므로 n+1까지
    ret = max(ret, dp[i]);
    if (i + t[i] <= n + 1) {  // n번째 날까지 검사해야 하므로 n+1까지
      dp[i + t[i]] = max(dp[i + t[i]], ret + p[i]);
    }
  }
  return ret;
}

int main() {
  fastIO;
  init();
  cout << solve() << "\n";
  return 0;
}