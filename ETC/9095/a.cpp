#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int t, n;

int dp[13];

int go(int num) {
  if (dp[num] > 0) return dp[num];

  dp[num] = go(num - 1) + go(num - 2) + go(num - 3);
  return dp[num];
}

void solve() {
  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << go(n) << "\n";
  }
}

void init() {
  memset(dp, 0, sizeof(dp));
  cin >> t;
  dp[0] = dp[1] = 1;
  dp[2] = 2;
}

int main() {
  fastIO;
  init();
  solve();
}