#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using namespace std;
int n;
int dp[100004][3];
void init() {
  cin >> n;
  dp[1][0] = dp[1][1] = dp[1][2] = 1;
}
void solve(int idx) {
  dp[idx][0] = (dp[idx - 1][0] + dp[idx - 1][1] + dp[idx - 1][2]) % 9901;
  dp[idx][1] = (dp[idx - 1][0] + dp[idx - 1][2]) % 9901;
  dp[idx][2] = (dp[idx - 1][0] + dp[idx - 1][1]) % 9901;
}
int main() {
  fastIO;
  init();
  for (int i = 2; i <= n; i++) {
    solve(i);
  }
  int ret = 0;
  for (int i = 0; i <= 2; i++) {
    ret += dp[n][i];
    ret %= 9901;
  }
  cout << ret % 9901 << "\n";
  return 0;
}