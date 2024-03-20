#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[104][100004];
vector<pair<int, int>> item;

int go(int i, int w) {
  // 기저사례
  if (i == n) return 0;
  // 메모이제이션
  if (dp[i][w] > 0) return dp[i][w];
  // 로직
  int v1 = -1;
  if (w + item[i].first <= k)
    v1 = item[i].second + go(i + 1, w + item[i].first);
  int v2 = go(i + 1, w);

  dp[i][w] = max(v1, v2);
  return dp[i][w];
}

int main() {
  // 초기화
  memset(dp, 0, sizeof(dp));
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    item.push_back({w, v});
  }

  cout << go(0, 0) << "\n";

  return 0;
}