#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, n, parent, child, n1, n2;
vector<int> graph[10004];
int visited[10004];

void init() {
  cin >> n;

  for (int i = 0; i < 10004; i++) {
    graph[i].clear();
  }
  memset(visited, 0, sizeof(visited));

  for (int i = 0; i < n - 1; i++) {
    cin >> parent >> child;
    graph[child].push_back(parent);
  }

  cin >> n1 >> n2;
}

void dfs(int curr) {
  if (visited[curr] == 1) {
    cout << curr << "\n";
    return;
  }
  visited[curr] = 1;

  for (auto it : graph[curr]) {
    dfs(it);
  }
}

// 현재 같은 선상에 있을 때 오류 발생
void go() {
  if (n1 == n2) {
    cout << n1 << "\n";
    return;
  }
  dfs(n1);
  dfs(n2);
}

int main() {
  fastIO;
  cin >> t;
  for (int _ = 0; _ < t; _++) {
    init();
    go();
  }
  return 0;
}