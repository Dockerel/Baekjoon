#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
int dp[50004];

void init() { cin >> n; }

void go() {
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    for (int j = 1; j * j <= i; j++) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  cout << dp[n] << "\n";
  return 0;
}