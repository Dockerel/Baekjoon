#include <bits/stdc++.h>
using namespace std;
int t, k, n;
int dp[20][20];
void init() {
  cin >> k;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < 20; i++) {
    dp[0][i] = i;
  }
}
int go(int floor, int room) {
  if (dp[floor][room]) {
    return dp[floor][room];
  }
  for (int i = 1; i <= room; i++) dp[floor][room] += go(floor - 1, i);
  return dp[floor][room];
}
int main() {
  cin >> t;
  while (t--) {
    init();
    cout << go(k, n) << "\n";
  }
}