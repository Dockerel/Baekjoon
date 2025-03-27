#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
int a[1001];
int dp[1001];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
}

void go() {
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < n; i++) {
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