#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, r, g, b;
int a[1004][4], dp[1004][4];  // 앞뒤로 색이 달라야함

pair<int, int> other(int n1) {
  if (n1 == 1) return {2, 3};
  if (n1 == 2) return {1, 3};
  if (n1 == 3) return {1, 2};
}

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1];
    cin >> a[i][2];
    cin >> a[i][3];
  }
  memset(dp, 0, sizeof(dp));
}

int solve(int idx, int c) {
  if (idx == 1) {
    return a[idx][c];
  }
  if (dp[idx][c]) {
    return dp[idx][c];
  }
  dp[idx][c] =
      min(solve(idx - 1, other(c).first), solve(idx - 1, other(c).second)) +
      a[idx][c];
  return dp[idx][c];
}

int main() {
  fastio;

  init();
  cout << min(solve(n, 1), min(solve(n, 2), solve(n, 3))) << "\n";

  return 0;
}