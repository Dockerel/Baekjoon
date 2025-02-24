#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, w, weight_sum, ret1, ret2;
vector<int> weights;
int dp[54][45002];

void init() {
  cin >> n;

  weight_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> w;
    weights.push_back(w);
    weight_sum += w;
  }

  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
}

void go() {
  for (auto weight : weights) {
    for (int i = n / 2; i > 0; i--) {
      for (int j = weight; j <= weight_sum; j++) {
        if (dp[i - 1][j - weight]) {
          dp[i][j] = 1;
        }
      }
    }
  }

  int diff = weight_sum;
  for (int i = 0; i <= weight_sum; i++) {
    if (dp[n / 2][i]) {
      if (diff > abs(weight_sum - 2 * i)) {
        diff = abs(weight_sum - 2 * i);
        ret1 = i;
      }
    }
  }

  ret2 = weight_sum - ret1;
  if (ret1 > ret2) swap(ret1, ret2);
  cout << ret1 << " " << ret2 << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}