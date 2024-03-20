#include <iostream>
using namespace std;
int n, k, w, v;
int dp[100004];  // 가치합 배열
int main() {
  cin >> n >> k;
  while (n--) {
    cin >> w >> v;
    for (int i = k; i >= w; i--) {
      dp[i] = max(dp[i], dp[i - w] + v);
    }
  }
  cout << dp[k] << "\n";
  return 0;
}