#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, k;
int a[104];
int dp[10004];

void init() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
}

void go() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j - a[i] >= 0) {
        dp[j] += dp[j - a[i]];
      }
    }
  }
  cout << dp[k] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}