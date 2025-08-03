#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, k;  // n : 도시의 개수, k분 이내로 여행
int walkT, walkM, bikeT, bikeM;

void init() { cin >> n >> k; }

void go() {
  int dp[k + 1];
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;

  for (int _ = 0; _ < n; _++) {
    cin >> walkT >> walkM >> bikeT >> bikeM;
    int ndp[k + 1];
    memset(ndp, -1, sizeof(ndp));
    for (int i = 0; i <= k; i++) {
      if (i - walkT >= 0 && dp[i - walkT] >= 0)
        ndp[i] = max(ndp[i], dp[i - walkT] + walkM);
      if (i - bikeT >= 0 && dp[i - bikeT] >= 0)
        ndp[i] = max(ndp[i], dp[i - bikeT] + bikeM);
    }

    for (int i = 0; i <= k; i++) {
      dp[i] = ndp[i];
    }
  }

  int ret = -1;
  for (int i = 0; i <= k; i++) {
    ret = max(ret, dp[i]);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}