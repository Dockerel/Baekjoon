#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
long long dp[11];

void init() {
  cin >> n;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
}

void go() {
  for (int _ = 0; _ <= n; _++) {
    for (int i = 1; i < 10; i++) {
      dp[i] = (dp[i] + dp[i - 1]) % 10007;
    }
  }
  cout << dp[9] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}