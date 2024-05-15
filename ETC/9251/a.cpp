#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
string s1, s2;
int ret = 0;
int dp[1004][1004];
void init() {
  cin >> s1;
  cin >> s2;
  memset(dp, 0, sizeof(dp));
  return;
}
void go() {
  for (int i = 1; i <= s1.length(); i++) {
    for (int j = 1; j <= s2.length(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        ret = max(ret, dp[i][j]);
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << ret << "\n";
}
int main() {
  fastIO;
  init();
  go();
}