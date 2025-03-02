#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

// 공부 시간의 한계(n)를 초과하지 않으면서 과목의 중요도 합이 최대가 되도록
// 최대 공부 시간 n, 과목수 k
// dp[i][j] : i번째 과목까지 확인 후 j시간 만큼 공부했을 때 얻을 수 있는 중요도

int n, k, l, t, sumT;
int dp[1004][10004];
vector<pair<int, int>> infos;

int ret;

void init() {
  cin >> n >> k;
  infos.push_back({0, 0});
  for (int i = 0; i < k; i++) {
    cin >> l >> t;
    infos.push_back({l, t});
    sumT += t;
  }
  ret = -1;
}

void go() {
  for (int i = 1; i <= k; i++) {
    tie(l, t) = infos[i];
    for (int j = 0; j <= n; j++) {
      if (j - t >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t] + l);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
      ret = max(ret, dp[i][j]);
    }
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}