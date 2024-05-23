#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string strs[3];

int dp[104][104][104];

void init() {
  for (int i = 0; i < 3; i++) {
    cin >> strs[i];
  }
}

int LCS(string s1, string s2, string s3) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < s1.length(); i++) {
    for (int j = 0; j < s2.length(); j++) {
      for (int k = 0; k < s3.length(); k++) {
        if (s1[i] == s2[j] && s1[i] == s3[k]) {
          dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
        } else {
          dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j][k],dp[i][j + 1][k],dp[i][j][k + 1]);
          dp[i + 1][j + 1][k + 1] = max(dp[i + 1][j + 1][k],dp[i + 1][j][k + 1], dp[i][j + 1][k + 1]);
        }
      }
    }
  }
  return dp[s1.length()][s2.length()][s3.length()];
}

void go() { cout << LCS(strs[0], strs[1], strs[2]) << "\n"; }

int main() {
  fastIO;
  init();
  go();
  return 0;
}