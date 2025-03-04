#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

// N개의 커피 중 몇 개를 골라 정확히 K만큼의 카페인을 섭취
// dp[i][j] : i번째 카페인까지 확인했을 떄 정확히 j만큼 섭취할 떄 마셔야 하는
// 커피 수(-1은 불가능)

int n, k;
int c[104];

int dp[100004];

void init() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= k; i++) {
    dp[i] = INF;
  }
}

void go() {
  for (int i = 1; i <= n; i++) {
    int caff = c[i];
    for (int j = k; j >= 0; j--) {
      if (j - caff >= 0) dp[j] = min(dp[j], dp[j - caff] + 1);
    }
  }

  cout << (dp[k] == INF ? -1 : dp[k]) << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}