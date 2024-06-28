#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define DIV 1000000009

using namespace std;

char a[3004][3004];
int dp[3004][3004];
int n, m, ret;
string s;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];
    }
  }
  memset(dp, 0, sizeof(dp));
  ret = 0;
}

void go() {
  dp[n - 1][m - 1] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      ret += dp[i][j] % DIV;
      ret %= DIV;
      if (i - 1 >= 0 && (a[i - 1][j] == 'S' || a[i - 1][j] == 'B')) {
        dp[i - 1][j] += dp[i][j];
        dp[i - 1][j] %= DIV;
      }
      if (j - 1 >= 0 && (a[i][j - 1] == 'E' || a[i][j - 1] == 'B')) {
        dp[i][j - 1] += dp[i][j];
        dp[i][j - 1] %= DIV;
      }
    }
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}