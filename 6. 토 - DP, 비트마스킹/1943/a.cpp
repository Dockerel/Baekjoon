#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, sum;
int type, amount;
vector<pair<int, int>> coins;

int dp[100004];

void init() {
  cin >> n;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  sum = 0;

  coins.clear();

  for (int _ = 0; _ < n; _++) {
    cin >> type >> amount;
    coins.push_back({type, amount});
    sum += (type * amount);
  }
}

void go() {
  if (sum % 2) {
    cout << "0\n";
    return;
  }

  for (auto it : coins) {
    tie(type, amount) = it;
    for (int i = sum / 2; i >= type; i--) {
      for (int j = 1; j <= it.second; j++) {
        if (i - type * j >= 0 && dp[i - type * j]) dp[i] = 1;
        if (dp[sum / 2]) {
          cout << "1\n";
          return;
        }
      }
    }
  }

  cout << dp[sum / 2] << "\n";
}

int main() {
  fastIO;
  for (int _ = 0; _ < 3; _++) {
    init();
    go();
  }
  return 0;
}