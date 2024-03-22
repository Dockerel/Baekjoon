#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int n, s, m;
int dp[54][1004], v[54];

void init() {
  cin >> n >> s >> m;
  for (int i = 1; i <= n; i++) cin >> v[i];
  memset(dp, 0, sizeof(dp));
  dp[0][s] = 1;
}

int go() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (dp[i - 1][j] == 1) {
        if (j + v[i] <= m) dp[i][j + v[i]] = 1;
        if (j - v[i] >= 0) dp[i][j - v[i]] = 1;
      }
    }
  }

  for (int i = m; i >= 0; i--) {
    if (dp[n][i]) {
      return i;
    }
  }
  return -1;
}

int main() {
  fastIO;
  init();
  cout << go() << "\n";
}