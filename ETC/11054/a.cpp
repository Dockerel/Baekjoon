#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, num;
vector<int> a;
int dp[1004];
int r_dp[1004];
int ret;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    a.push_back(num);
    dp[i] = r_dp[i] = 1;
  }

  ret = -1;
}

void go() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  reverse(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        r_dp[i] = max(r_dp[i], r_dp[j] + 1);
      }
    }
  }

  reverse(r_dp, r_dp + n);

  for (int i = 0; i < n; i++) {
    ret = max(ret, dp[i] + r_dp[i] - 1);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}

// reference img from
// https://dontdiethere.tistory.com/77