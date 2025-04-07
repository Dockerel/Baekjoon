#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

int c, n, n1, n2;
vector<pair<int, int>> infos;
int dp[99004];

void init() {
  cin >> c >> n;
  for (int _ = 0; _ < n; _++) {
    cin >> n1 >> n2;
    infos.push_back({n1, n2});
  }

  dp[0] = 0;
  for (int i = 1; i <= c; i++) {
    dp[i] = INF;
  }
}

void go() {
  for (auto it : infos) {
    for (int i = 1; i <= c * 99; i++) {
      int prv = (i - it.second <= 0 ? 0 : i - it.second);
      dp[i] = min(dp[i], dp[prv] + it.first);
    }
  }
  cout << dp[c] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}