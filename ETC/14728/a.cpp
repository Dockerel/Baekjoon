#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, t, k, s;
int dp[10004];

void init() { cin >> n >> t; }

void go() {
  for (int _ = 0; _ < n; _++) {
    cin >> k >> s;
    for (int i = t; i >= k; i--) {
      dp[i] = max(dp[i], dp[i - k] + s);
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