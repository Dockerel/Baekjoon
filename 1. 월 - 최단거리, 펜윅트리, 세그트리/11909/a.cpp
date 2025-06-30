#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
#define pii pair<int, int>
#define pipii pair<int, pii>
#define ff first
#define ss second

using namespace std;

int n, y, x, curr, ret;

int a[2224][2224];
int dp[2224][2224];

int dy[2] = {1, 0};
int dx[2] = {0, 1};

priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      dp[i][j] = INF;
    }
  }
}

void go() {
  dp[0][0] = 0;
  pq.push({0, {y, x}});

  while (!pq.empty()) {
    int cost = pq.top().ff;
    tie(y, x) = pq.top().ss;
    pq.pop();

    for (int i = 0; i < 2; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny >= n || nx >= n) continue;

      int nextCost = cost;
      if (a[ny][nx] >= a[y][x]) {
        nextCost += (a[ny][nx] + 1 - a[y][x]);
      }

      if (nextCost < dp[ny][nx]) {
        dp[ny][nx] = nextCost;
        pq.push({nextCost, {ny, nx}});
      }
    }
  }

  cout << dp[n - 1][n - 1] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}