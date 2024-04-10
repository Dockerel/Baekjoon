#include <bits/stdc++.h>
using namespace std;

int dp[1004][1004];
string s1, s2;

void init() {
  cin >> s1;
  cin >> s2;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= s1.length(); i++) {
    for (int j = 0; j <= s2.length(); j++) {
      if (i == 0) {
        dp[i][j] = j;
      } else {
        if (j == 0) {
          dp[i][j] = i;
        }
      }
    }
  }
  return;
}

void go() {
  for (int i = 1; i <= s1.length(); i++) {
    for (int j = 1; j <= s2.length(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] =
            min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1]));
      } else {
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
      }
    }
  }

  return;
}

int main() {
  init();
  go();
  cout << dp[s1.length()][s2.length()] << "\n";
  return 0;
}