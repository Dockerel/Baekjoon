#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int n, m, v, v1, v2;
vector<int> graph[1004];
int visited[1004];

void init() {
  cin >> n >> m >> v;
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }
}

void dfs(int num) {
  cout << num << " ";

  for (int it : graph[num]) {
    if (!visited[it]) {
      visited[it] = 1;
      dfs(it);
    }
  }
}

void bfs(int num) {
  queue<int> q;
  q.push(num);

  while (!q.empty()) {
    num = q.front();
    cout << num << " ";
    q.pop();

    for (int it : graph[num]) {
      if (!visited[it]) {
        visited[it] = 1;
        q.push(it);
      }
    }
  }
}

int main() {
  fastIO;
  init();

  memset(visited, 0, sizeof(visited));
  visited[v] = 1;
  dfs(v);
  cout << "\n";

  memset(visited, 0, sizeof(visited));
  visited[v] = 1;
  bfs(v);
  cout << "\n";
}