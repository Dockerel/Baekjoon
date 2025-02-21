#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

using namespace std;

ll dp[34][34];

void init() { memset(dp, 0, sizeof(dp)); }

void go() {
  for (int w = 0; w <= 30; w++) {
    for (int h = 0; h <= 30; h++) {
      if (w < h) continue;
      if (h == 0)
        dp[w][h] = 1;
      else
        dp[w][h] = dp[w][h - 1] + dp[w - 1][h];
    }
  }
}

int main() {
  fastIO;
  init();
  go();

  int n;
  while (1) {
    cin >> n;
    if (n == 0) break;
    cout << dp[n][n] << "\n";
  }

  return 0;
}