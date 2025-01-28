#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, n, m;
int n1, n2, ret;
vector<int> graph[1004];
int isGraph;
int visited[1004];

void init() { cin >> t; }

void dfs(int here) {
  visited[here] = 1;

  for (auto it : graph[here]) {
    if (visited[it] == 0) {
      dfs(it);
    }
  }
}

void go() {
  cin >> n;  // 노드의 수
  cin >> m;  // 간선의 수
  ret = isGraph = 0;
  memset(visited, 0, sizeof(visited));
  for (int i = 1; i <= n; i++) graph[i].clear();

  for (int _ = 0; _ < m; _++) {
    cin >> n1 >> n2;
    if (find(graph[n1].begin(), graph[n1].end(), n2) != graph[n1].end())
      isGraph = 1;
    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }

  // 트리가 되려면?
  // 1. 모두 연결되어 있어야 함 -> dfs/bfs 돌려서 확인
  // 2. 사이클 없어야 함 -> dfs/bfs 중 확인

  // dfs
  dfs(1);

  // visit한 노드 개수 -> 1 개수 세기
  for (int i = 1; i <= n; i++) {
    if (visited[i]) ret++;
  }
  // 끊어진 경우
  if (ret != n) isGraph = 1;
  // 사이클 존재 or 끊어진 경우
  if (m != n - 1) isGraph = 1;

  cout << (isGraph ? "graph\n" : "tree\n");
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < t; _++) {
    go();
  }
  return 0;
}