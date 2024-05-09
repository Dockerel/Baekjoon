#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, curr;
long long _sum;

vector<int> graph[200004];
vector<pair<int, int>> ret;
int visited[200004];
int dfs_val[200004];
int bfs_val[200004];

void init() {
  cin >> n;
  memset(dfs_val, 0, sizeof(dfs_val));
  memset(bfs_val, 0, sizeof(dfs_val));
  _sum = 0;
}

void make_graph() {
  for (int i = 1; i <= n / 2; i++) {
    graph[i].push_back(i + 1);
    ret.push_back({i, i + 1});
  }
  for (int i = n / 2 + 2; i <= n; i++) {
    graph[1].push_back(i);
    ret.push_back({1, i});
  }
}

void dfs(int here) {
  visited[here] = 1;
  dfs_val[here] = curr++;
  for (auto it : graph[here]) {
    if (visited[it] == 0) {
      dfs(it);
    }
  }
}

void bfs(int here) {
  queue<int> q;
  q.push(here);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    visited[node] = 1;
    bfs_val[node] = curr++;
    for (auto it : graph[node]) {
      if (visited[it] == 0) {
        q.push(it);
      }
    }
  }
}

void go() {
  make_graph();
  memset(visited, 0, sizeof(visited));
  curr = 0;
  dfs(1);
  memset(visited, 0, sizeof(visited));
  curr = 0;
  bfs(1);

  for (int i = 1; i <= n; i++) {
    _sum += abs(dfs_val[i] - bfs_val[i]);
  }

  cout << _sum << "\n";
  for (auto it : ret) {
    cout << it.first << " " << it.second << "\n";
  }
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}
