#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int dp[104][10004];
int t, k, p, n;

void init() {
  cin >> t;
  cin >> k;
  dp[0][0] = 1;
}

void go() {
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j <= t; j++) {
      dp[i][j] = dp[i - 1][j];
    }

    cin >> p >> n;
    for (int price = p; price <= p * n; price += p) {
      for (int j = price; j <= t; j++) {
        if (dp[i - 1][j - price]) {
          dp[i][j] += dp[i - 1][j - price];
        }
      }
    }
  }
  cout << dp[k][t] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}