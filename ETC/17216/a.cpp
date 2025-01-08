#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, num, ret;
vector<int> a;
int dp[1004];

void init() {
  cin >> n;
  for (int _ = 0; _ < n; _++) {
    cin >> num;
    a.push_back(num);
  }
  memset(dp, 0, sizeof(dp));
  ret = 0;
  dp[0] = a[0];
}

void go() {
  // 감소하는 최대 합 부분 수열
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] > a[i]) {
        dp[i] = max(dp[i], dp[j] + a[i]);
      }
      if (dp[i] == 0) {
        dp[i] = a[i];
      }
    }
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