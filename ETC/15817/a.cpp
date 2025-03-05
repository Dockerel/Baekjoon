#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, x, l, c;

int dp[10004];  // i번째 파이프까지 확인했을 때 만들 수 있는 길이가 dp[i]

void init() {
  cin >> n >> x;
  dp[0] = 1;
}

void go() {
  for (int _ = 0; _ < n; _++) {
    cin >> l >> c;
    for (int i = x; i >= 0; i--) {
      for (int k = 1; k <= c && i - l * k >= 0; k++) {
        dp[i] += dp[i - l * k];
      }
    }
  }
  cout << dp[x] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}