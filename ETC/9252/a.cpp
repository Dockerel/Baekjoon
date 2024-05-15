#include <iostream>

using namespace std;

string s1, s2, ret = "";
int dp[1004][1004];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s1;
  cin >> s2;
  for (int i = 1; i <= s1.length(); i++) {
    for (int j = 1; j <= s2.length(); j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
  }
  int i = s1.length();
  int j = s2.length();
  while (dp[i][j]) {
    if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else {
      ret = s1[i - 1] + ret;
      i--;
      j--;
    }
  }
  cout << ret.length() << "\n";
  cout << ret << "\n";
  return 0;
}