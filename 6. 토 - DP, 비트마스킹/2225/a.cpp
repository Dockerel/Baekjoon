#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, k;

int dp[204];

void init() {
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    dp[i] = 1;
  }
}

void go() {
  for (int _ = 0; _ <= k - 2; _++) {
    for (int i = 1; i <= n; i++) {
      dp[i] = (dp[i] + dp[i - 1]) % 1000000000;
    }
  }
  cout << dp[n] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}