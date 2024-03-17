#include <bits/stdc++.h>
using namespace std;
int n, k, t, ret = INFINITY;
int visited[100004];
void bfs(int x) {
  queue<pair<int, int>> Q;
  Q.push({x, 0});
  while (!Q.empty()) {
    tie(x, t) = Q.front();
    visited[x] = 1;
    Q.pop();

    if (x == k) {
      ret = min(ret, t);
    }

    if (x + 1 >= 0 && x + 1 < 100001 && !visited[x + 1]) Q.push({x + 1, t + 1});
    if (x - 1 >= 0 && x - 1 < 100001 && !visited[x - 1]) Q.push({x - 1, t + 1});
    if (x * 2 >= 0 && x * 2 < 100001 && !visited[x * 2]) Q.push({x * 2, t});
  }
}
int main() {
  cin >> n >> k;
  bfs(n);
  cout << ret << "\n";
  return 0;
}