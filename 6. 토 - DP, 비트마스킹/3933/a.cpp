#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 32768

using namespace std;

int n;
int dp[5][MAX + 1];

void init() {
  dp[0][0] = 1;
  for (int i = 1; i * i <= MAX; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = i * i; k <= MAX; k++) {
        dp[j][k] += dp[j - 1][k - i * i];
      }
    }
  }
}

void go() {
  cin >> n;
  do {
    cout << dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n] << "\n";
    cin >> n;
  } while (n != 0);
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}