#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int n;
int a[304], dp[304];

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, 0, sizeof(dp));
  dp[1] = a[1];
  dp[2] = a[1] + a[2];
  dp[3] = a[3] + max(a[1], a[2]);
  return;
}

int solve() {
  // dp[n] = a[n] + max(a[n-1] + dp[n-3], dp[n-2])
  for (int i = 4; i <= n; i++) {
    dp[i] = a[i] + max(a[i - 1] + dp[i - 3], dp[i - 2]);
  }
  return dp[n];
}

int main() {
  fastIO;
  init();
  cout << solve() << "\n";

  return 0;
}