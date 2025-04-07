#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int n, m, c, p;
double temp_m, temp_p;
vector<pii> candies;

int dp[10004];

void init() {
  cin >> n >> temp_m;
  m = temp_m * 100 + 0.5;
  if (n == 0 && m == 0) {
    exit(0);
  }
  candies.clear();
  for (int _ = 0; _ < n; _++) {
    cin >> c >> temp_p;
    p = temp_p * 100 + 0.5;
    candies.push_back({p, c});
  }
  sort(candies.begin(), candies.end());
  memset(dp, 0, sizeof(dp));
}

void go() {
  while (1) {
    init();

    for (int i = 0; i <= m; i++) {
      for (auto it : candies) {
        if (i - it.first < 0) break;
        dp[i] = max(dp[i], dp[i - it.first] + it.second);
      }
    }

    cout << dp[m] << "\n";
  }
}

int main() {
  fastIO;
  go();
  return 0;
}