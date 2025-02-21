#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 10004

using namespace std;

int n, k, val;
int dp[MAX];
set<int> coins;

void init() {
  cin >> n >> k;
  memset(dp, 0, sizeof(dp));
  for (int _ = 0; _ < n; _++) {
    cin >> val;
    coins.insert(val);
  }
}

void go() {
  dp[0] = 0;
  for (int i = 1; i <= k; i++) {
    dp[i] = MAX;
  }

  for (auto it = coins.begin(); it != coins.end(); it++) {
    int money = *it;
    for (int i = 1; i <= k; i++) {
      if (i - money < 0) continue;
      dp[i] = min(dp[i], dp[i - money] + 1);
    }
  }

  cout << (dp[k] == MAX ? -1 : dp[k]) << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}