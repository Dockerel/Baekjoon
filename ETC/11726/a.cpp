#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1004];

void init() {
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
}

int solve() {
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
    dp[i] %= 10007;
  }
  return dp[n];
}

int main() {
  init();
  cout << solve() << "\n";

  return 0;
}