#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 104

using namespace std;

int n;
int a[MAX][MAX];
string dp[MAX][MAX];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      dp[i][j] = "0";
    }
  }
  dp[0][0] = "1";
}

string strAdd(string s1, string s2) {
  if (s1.size() > s2.size())
    s2 = string((s1.size() - s2.size()), '0') + s2;
  else if (s1.size() < s2.size())
    s1 = string((s2.size() - s1.size()), '0') + s1;

  string result = "";
  int carry = 0;

  for (int i = s1.size() - 1; i >= 0; i--) {
    int _sum = (s1[i] - '0') + (s2[i] - '0') + carry;
    result += (_sum % 10) + '0';
    carry = _sum / 10;
  }

  if (carry) result += carry + '0';
  reverse(result.begin(), result.end());
  return result;
}

void go() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) continue;
      if (i == n - 1 && j == n - 1) continue;

      int nxtY = i + a[i][j];
      if (nxtY < n) dp[nxtY][j] = strAdd(dp[nxtY][j], dp[i][j]);

      int nxtX = j + a[i][j];
      if (nxtX < n) dp[i][nxtX] = strAdd(dp[i][nxtX], dp[i][j]);
    }
  }

  cout << dp[n - 1][n - 1] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}
