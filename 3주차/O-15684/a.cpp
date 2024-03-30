#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
const int INF = 987654321;
int n, m, h, n1, n2, ret = INF;
int visited[34][14];

void init() {
  memset(visited, 0, sizeof(visited));
  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) {
    cin >> n1 >> n2;
    visited[n1][n2] = 1;
  }
  return;
}

bool check() {
  for (int i = 1; i <= n; i++) {
    int start = i;
    for (int j = 1; j <= h; j++) {
      if (visited[j][start])
        start++;
      else if (visited[j][start - 1])
        start--;
    }
    if (start != i) return false;
  }
  return true;
}

void go(int here, int cnt) {
  if (cnt > 3 || cnt >= ret) return;
  if (check()) {
    ret = min(ret, cnt);
    return;
  }
  for (int i = here; i <= h; i++) {
    for (int j = 1; j <= n; j++) {
      if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
      visited[i][j] = 1;
      go(i, cnt + 1);
      visited[i][j] = 0;
    }
  }
}

int main() {
  fastIO;

  init();
  go(1, 0);
  cout << ((ret == INF) ? -1 : ret) << "\n";

  return 0;
}