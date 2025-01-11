#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int visited[104];
int transfer[104];

int n, m, from, to, curr, cnt;

queue<pair<int, int>> q;

void init() {
  memset(visited, -1, sizeof(visited));
  memset(transfer, -1, sizeof(transfer));

  cin >> n >> m;
  for (int _ = 0; _ < n + m; _++) {
    cin >> from >> to;
    transfer[from] = to;
  }

  visited[1] = 0;
}

void go() {
  q.push({1, 0});
  while (!q.empty()) {
    tie(curr, cnt) = q.front();
    q.pop();
    for (int i = 1; i <= 6; i++) {
      int next = curr + i;
      if (transfer[next] != -1) {
        next = transfer[next];
      }

      if (visited[next] == -1) {
        visited[next] = cnt + 1;
        q.push({next, cnt + 1});
      }
    }
  }
  cout << visited[100] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}