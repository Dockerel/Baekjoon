#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

// n을 1, 2, 3의 합으로 나타내는 방법의 수

int n, num;
vector<int> nums;
int dp[10001][4];

void init() {
  cin >> n;
  for (int _ = 0; _ < n; _++) {
    cin >> num;
    nums.push_back(num);
  }
  dp[1][1] = 1;

  dp[2][1] = 1;
  dp[2][2] = 1;

  dp[3][1] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;
}

void go() {
  int max_num = *max_element(nums.begin(), nums.end());
  for (int i = 4; i <= max_num; i++) {
    dp[i][1] = dp[i - 1][1];
    dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
  }

  for (auto it : nums) {
    cout << dp[it][1] + dp[it][2] + dp[it][3] << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}