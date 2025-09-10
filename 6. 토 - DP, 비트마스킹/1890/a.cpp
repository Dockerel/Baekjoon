#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
int n;
int a[104][104];
ll dp[104][104];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  dp[0][0] = 1;
}

int main() {
  fastIO;
  input();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != 0 && dp[i][j] != 0) {
        if (i + a[i][j] < n) {
          dp[i + a[i][j]][j] += dp[i][j];
        }
        if (j + a[i][j] < n) {
          dp[i][j + a[i][j]] += dp[i][j];
        }
      }
    }
  }

  cout << dp[n - 1][n - 1] << "\n";

  return 0;
}