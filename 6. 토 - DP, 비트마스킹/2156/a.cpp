#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, num;
vector<int> wines;

int dp[10004];

void init() {
  cin >> n;
  wines.push_back(0);
  for (int _ = 0; _ < n; _++) {
    cin >> num;
    wines.push_back(num);
  }
}

void go() {
  for (int i = 1; i <= n; i++) {
    if (i <= 2) {
      dp[i] = dp[i - 1] + wines[i];
      continue;
    }
    if (i == 3) {
      dp[i] =
          max({wines[1] + wines[2], wines[2] + wines[3], wines[1] + wines[3]});
      continue;
    }
    dp[i] = max(
        {dp[i - 1], dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i]});
  }
  cout << dp[n] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}