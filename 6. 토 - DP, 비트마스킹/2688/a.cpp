#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

using namespace std;

ll t, n;
ll ret;

ll dp[10], temp[10];

void init() { cin >> t; }

void go() {
  cin >> n;

  if (n == 1) {
    cout << "10\n";
    return;
  }

  for (int i = 0; i < 10; i++) {
    dp[i] = 1;
  }

  for (int _ = 0; _ < n - 2; _++) {
    // temp clear
    for (int i = 0; i < 10; i++) {
      temp[i] = 0;
    }
    // 분류 작업
    for (int i = 0; i < 10; i++) {
      for (int j = i; j < 10; j++) {
        temp[j] += dp[i];
      }
    }
    // temp to dp
    for (int i = 0; i < 10; i++) {
      dp[i] = temp[i];
    }
  }

  ret = 0;
  for (int i = 0; i < 10; i++) {
    ret += dp[i] * (10 - i);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  while (t--) {
    go();
  }
  return 0;
}