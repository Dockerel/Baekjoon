#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using namespace std;
int n, num, ret = -INFINITY;
int dp[100004];
int main() {
  fastIO;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num;
    dp[i] = max(num, dp[i - 1] + num);
    ret = max(ret, dp[i]);
  };
  cout << ret << "\n";
  return 0;
}