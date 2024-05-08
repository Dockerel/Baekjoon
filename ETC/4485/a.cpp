#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 130
#define INF 987654321

using namespace std;

bool exit_flag;
int n, num;
int maze[MAX][MAX], cost[MAX][MAX];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      cost[i][j] = INF;
    }
  }
}

void input() {
  cin >> n;

  if (n == 0) {
    exit_flag = true;
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> maze[i][j];
      cost[i][j] = INF;
    }
  }
}

void go() {
  priority_queue<pair<int, pair<int, int>>> pq;

  cost[0][0] = maze[0][0];
  pq.push({-cost[0][0], {0, 0}});

  while (!pq.empty()) {
    auto it = pq.top();
    int cur_cost = (-it.first);
    int y, x;
    tie(y, x) = it.second;
    pq.pop();
    if (cur_cost > cost[y][x]) continue;
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (y < 0 || y >= n || x < 0 || x >= n) continue;
      int new_cost = cur_cost + maze[ny][nx];
      if (new_cost < cost[ny][nx]) {
        cost[ny][nx] = new_cost;
        pq.push({-cost[ny][nx], {ny, nx}});
      }
    }
  }
  cout << "Problem " << num++ << ": " << cost[n - 1][n - 1] << "\n";
}

int main() {
  fastIO;
  exit_flag = false;
  num = 1;
  while (1) {
    init();
    input();
    if (exit_flag) break;
    go();
  }
}