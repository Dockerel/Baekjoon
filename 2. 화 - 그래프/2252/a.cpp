#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 32004
using namespace std;
int n, m, a, b;
vector<int> graph[MAX];
int in_degree[MAX], visited[MAX];
void init() {
  memset(in_degree, 0, sizeof(in_degree));
  memset(visited, 0, sizeof(visited));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    graph[b].push_back(a);
    in_degree[a] = 1;
  }
  return;
}
void go(int here) {
  visited[here] = 1;
  for (int next : graph[here]) {
    if (!visited[next]) {
      go(next);
    }
  }
  cout << here << " ";
}
int main() {
  fastIO;
  init();
  for (int i = 1; i <= n; i++) {
    if (!in_degree[i]) {
      go(i);
    }
  }
  cout << "\n";
  return 0;
}