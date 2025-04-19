#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int dp[10004];
int t, k, p, n;

void init() {
  cin >> t;
  cin >> k;
  dp[0] = 1;
}

void go() {
  for (int _ = 0; _ < k; _++) {
    cin >> p >> n;
    for (int j = t; j >= 0; j--) {
      for (int i = p; i <= p * n; i += p) {
        if (j - i >= 0 && dp[j - i]) {
          dp[j] += dp[j - i];
        }
      }
    }
  }
  cout << dp[t] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}