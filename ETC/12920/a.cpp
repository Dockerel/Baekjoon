#include <iostream>
#include <vector>
using namespace std;
int n, m;
int v, c, k, w;
int dp[10004];
vector<pair<int, int>> divided_item;
int main() {
  cin >> n >> m;

  while (n--) {
    cin >> v >> c >> k;
    for (int i = k; i > 0; i >>= 1) {
      int part = i - (i >> 1);
      divided_item.push_back({v * part, c * part});
    }
  }

  for (int i = 0; i < divided_item.size(); i++) {
    w = divided_item[i].first;
    v = divided_item[i].second;
    for (int j = m; j >= w; j--) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }

  cout << dp[m] << "\n";

  return 0;
}