#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
int dp[2004][2004];

void init() { cin >> n >> m; }

void go() {
  int ret = 0;
  for (int i = n; i <= m; i++) {
    for (int j = 1; j <= i; j++) {
      int _gcd = __gcd(i, j);
      auto temp = &dp[i / _gcd][j / _gcd];
      if (*temp == 0) {
        *temp = 1;
        ret++;
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}