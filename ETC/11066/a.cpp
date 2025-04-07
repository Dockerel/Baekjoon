#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

int t, n, p;
vector<int> pages;
vector<int> prefix_pages;

int dp[504][504];

void init() {
  cin >> n;
  prefix_pages.push_back(0);
  for (int i = 0; i < n; i++) {
    cin >> p;
    pages.push_back(p);
    // 누적합
    prefix_pages.push_back(prefix_pages[prefix_pages.size() - 1] + p);
  }
}

void go() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i != j) {
        dp[i][j] = INF;
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      for (int k = j; k < j + i - 1; k++) {
        dp[j][j + i - 1] =
            min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] +
                                      prefix_pages[j + i] - prefix_pages[j]);
      }
    }
  }

  cout << dp[0][n - 1] << "\n";
}

int main() {
  fastIO;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    memset(dp, 0, sizeof(dp));
    init();
    go();
    pages.clear();
    prefix_pages.clear();
  }
  return 0;
}