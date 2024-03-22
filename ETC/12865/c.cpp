#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, k;
int dp[104][100004], wgt[104], val[104];

void init() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> wgt[i] >> val[i];
  }
  memset(dp, 0, sizeof(dp));
  return;
}

int go(int idx, int w) {  // dp[i][j] : i번째 인덱스에서 현재 상태
  if (idx == n) return 0;
  if (dp[idx][w]) return dp[idx][w];

  int v1 = 0;
  if (w + wgt[idx] <= k) {
    v1 = go(idx + 1, w + wgt[idx]) + val[idx];
  }
  dp[idx][w] = max(v1, go(idx + 1, w));
  return dp[idx][w];
}

int main() {
  fastio;

  init();
  cout << go(0, 0) << "\n";

  return 0;
}