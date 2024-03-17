#include <bits/stdc++.h>
using namespace std;
int n, k, ret = INFINITY;
int visited[100004];
int graph[100004];
vector<int> ans;
void go(int x, int t) {
  queue<pair<int, int>> Q;
  visited[x] = 1;
  Q.push({x, t});

  while (!Q.empty()) {
    tie(x, t) = Q.front();
    Q.pop();

    if (x == k) {
      ret = min(ret, t);
      continue;
    }

    if (x + 1 >= 0 && x + 1 < 100001 && !visited[x + 1]) {
      Q.push({x + 1, t + 1});
      visited[x + 1] = 1;
      graph[x + 1] = x;
    }
    if (x - 1 >= 0 && x - 1 < 100001 && !visited[x - 1]) {
      Q.push({x - 1, t + 1});
      visited[x - 1] = 1;
      graph[x - 1] = x;
    }
    if (x * 2 >= 0 && x * 2 < 100001 && !visited[x * 2]) {
      Q.push({x * 2, t + 1});
      visited[x * 2] = 1;
      graph[x * 2] = x;
    }
  }
}
void back(int x) {
  if (x == n) {
    cout << ans.size() << "\n";
    cout << n << " ";
    for (int i = ans.size() - 1; i >= 0; i--) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    exit(0);
  } else {
    ans.push_back(x);
    back(graph[x]);
  }
}
int main() {
  cin >> n >> k;
  go(n, 0);
  back(k);
  return 0;
}