#include <bits/stdc++.h>
using namespace std;
int n, k, min_nb = INFINITY;
int visited[100004];
int ret = 0;
void bfs(int x, int time) {
  queue<pair<int, int>> Q;
  Q.push({x, time});
  visited[x] = 1;

  while (!Q.empty()) {
    tie(x, time) = Q.front();
    Q.pop();
    visited[x] = 1;

    if (x == k) {
      if (min_nb > time) {
        ret = 1;
        min_nb = time;
      } else if (min_nb == time)
        ret++;
    }

    if (x - 1 >= 0 && x - 1 < 100004 && visited[x - 1] == 0)
      Q.push({x - 1, time + 1});
    if (x + 1 >= 0 && x + 1 < 100004 && visited[x + 1] == 0)
      Q.push({x + 1, time + 1});
    if (x * 2 >= 0 && x * 2 < 100004 && visited[x * 2] == 0)
      Q.push({x * 2, time + 1});
  }
}
int main() {
  cin >> n >> k;
  memset(visited, 0, sizeof(visited));
  bfs(n, 0);
  cout << min_nb << "\n" << ret << "\n";
  return 0;
}