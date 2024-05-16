#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string strs[3];

int dp[104][104];

void init() {
  for (int i = 0; i < 3; i++) {
    cin >> strs[i];
  }
}

string LCS(string s1, string s2) { memset(dp, 0, sizeof(dp)); }

void go() {
  string _prev = strs[0];
  for (int i = 1; i <= 2; i++) {
    _prev = LCS(_prev, strs[i]);
  }
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}