#include <bits/stdc++.h>
#define fastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);

using namespace std;
int t, w, tr;
int a[1004];
int dp[1004][3][34];

void init() {
  memset(dp, 0, sizeof(dp));
  cin >> t >> w;
  for (int i = 1; i <= t; i++) cin >> a[i];
  return;
}
// dp[a][b][c] : a번째 자두가 b번째 나무에서 떨어질 때 c번 움직인 상황
void solve() {
  for (int i = 1; i <= t; i++) {        // index
    for (int j = 1; j <= w + 1; j++) {  // 현재 위치
      if (a[i] == 1) {
        dp[i][1][j] = max(dp[i - 1][1][j] + 1, dp[i - 1][2][j - 1] + 1);
        dp[i][2][j] = max(dp[i - 1][1][j - 1], dp[i - 1][2][j]);
      } else if (a[i] == 2) {
        if (i == 1 && j == 1)
          continue;  // 처음 상황에서는 이전 상황이 존재할 수가 없으므로 패스
        dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][2][j - 1]);
        dp[i][2][j] = max(dp[i - 1][1][j - 1] + 1, dp[i - 1][2][j] + 1);
      }
    }
  }

  int ret = -1;
  for (int i = 1; i <= w + 1; i++) {
    ret = max(ret, max(dp[t][1][i], dp[t][2][i]));
  }
  cout << ret << "\n";
}

int main() {
  fastIO;

  init();
  solve();

  return 0;
}