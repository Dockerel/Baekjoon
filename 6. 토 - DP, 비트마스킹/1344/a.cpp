#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

double goalP1, goalP2;

double dp[20][20][20];

void init() {
  cin >> goalP1;
  cin >> goalP2;

  memset(dp, -1, sizeof(dp));
}

int isPrime(int n) {
  if (n < 2) return 0;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

double dfs(int depth, int wins1, int wins2) {
  if (depth == 18) {
    if (isPrime(wins1) || isPrime(wins2)) return 1.0;
    return 0.0;
  }
  double& ret = dp[depth][wins1][wins2];
  if (ret > -0.5) return ret;
  ret = 0.0;
  ret += dfs(depth + 1, wins1, wins2) * (1 - goalP1) * (1 - goalP2);
  ret += dfs(depth + 1, wins1 + 1, wins2) * goalP1 * (1 - goalP2);
  ret += dfs(depth + 1, wins1, wins2 + 1) * (1 - goalP1) * goalP2;
  ret += dfs(depth + 1, wins1 + 1, wins2 + 1) * goalP1 * goalP2;
  return ret;
}

void go() {
  // 적어도 한 팀이 골을 득점할 확률
  // 18개의 구간
  // 결국 18번 경기하면서 서로 이기고 질 확률 곱해서 싹다 더하기
  goalP1 /= 100;
  goalP2 /= 100;

  cout << dfs(0, 0, 0) << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}