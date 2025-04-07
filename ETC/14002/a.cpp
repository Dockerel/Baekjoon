#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, ai;
int a[1004];
int dp[1004];

int ret1;
vector<int> ret2;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[i] = 1;
  }
}

void go() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int val, idx;
  val = idx = -1;
  for (int i = 0; i < n; i++) {
    if (dp[i] > val) {
      val = dp[i];
      idx = i;
    }
  }
  ret1 = val;
  ret2.push_back(a[idx]);

  for (int i = idx - 1; i >= 0; i--) {
    if (a[i] < a[idx] && dp[i] == val - 1) {
      ret2.push_back(a[i]);
      idx = i;
      val = dp[i];
    }
  }

  cout << ret1 << "\n";
  for (int i = ret2.size() - 1; i >= 0; i--) {
    cout << ret2[i] << " ";
  }
  cout << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}