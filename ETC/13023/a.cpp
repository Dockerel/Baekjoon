#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, a, b;
int visited[2004];
vector<int> graph[2004];

void init() {
  cin >> n >> m;
  for (int _ = 0; _ < m; _++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}

void go(int curr, int size) {
  if (size == 5) {
    cout << "1\n";
    exit(0);
  }

  for (auto it : graph[curr]) {
    if (visited[it]) continue;
    visited[it] = 1;
    go(it, size + 1);
    visited[it] = 0;
  }
}

int main() {
  fastIO;
  init();
  for (int i = 0; i < n; i++) {
    visited[i] = 1;
    go(i, 1);
    visited[i] = 0;
  }
  cout << "0\n";
  return 0;
}