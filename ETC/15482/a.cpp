#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string s;

struct hangul {
  char c1;
  char c2;
  char c3;
};

bool operator==(hangul a, hangul b) {
  return a.c1 == b.c1 && a.c2 == b.c2 && a.c3 == b.c3;
}

vector<hangul> s1;
vector<hangul> s2;

int dp[1004][1004];

void init() {
  for (int k = 0; k < 2; k++) {
    cin >> s;
    for (int i = 0; i < s.length(); i += 3) {
      hangul temp;
      for (int j = 0; j < 3; j++) {
        if (j == 0) temp.c1 = s[i + j];
        if (j == 1) temp.c2 = s[i + j];
        if (j == 2) temp.c3 = s[i + j];
      }
      k == 0 ? s1.push_back(temp) : s2.push_back(temp);
    }
  }
  memset(dp, 0, sizeof(dp));
}

void go() {
  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  cout << dp[s1.size()][s2.size()] << "\n";
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}