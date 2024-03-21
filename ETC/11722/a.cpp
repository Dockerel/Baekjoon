#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, a[1004], dp[1004];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, 0, sizeof(dp));
}
int solve(int num) {
  if (num < 0) {
    return 0;
  }
  if (dp[num] != 0) {
    return dp[num];
  }
  for (int i = 0; i < num; i++) {
    if (a[i] > a[num]) {
      dp[num] = max(dp[num], solve(i) + 1);
    }
  }
  return dp[num];
}

int main() {
  fastio;

  init();
  cout << solve(n) << "\n";

  return 0;
}