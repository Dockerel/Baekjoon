#include <iostream>
using namespace std;
int n, dp[24];
int main() {
  cin >> n;
  dp[0] = 0;
  dp[1] = 1;
  if (n <= 1) {
    cout << dp[n] << "\n";
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n] << "\n";
  return 0;
}