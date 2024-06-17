#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int v, e, n1, n2, w, ret;
int visited[10004];
vector<pii> graph[10004];

struct cmp {
  bool operator()(pii a, pii b) { return a.second > b.second; }
};

priority_queue<pii, vector<pii>, cmp> pq;

void init() {
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    cin >> n1 >> n2 >> w;
    graph[n1].push_back({n2, w});
    graph[n2].push_back({n1, w});
  }
  memset(visited, 0, sizeof(visited));
  return;
}

void go() {
  for (auto it : graph[1]) {
    pq.push(it);
  }
  visited[1] = 1;
  while (!pq.empty()) {
    auto temp = pq.top();
    pq.pop();
    int to;
    to = temp.first;
    if (visited[to] == 0) {
      visited[to] = 1;
      ret += temp.second;
      for (auto it : graph[to]) {
        if (visited[it.first] == 0) pq.push(it);
      }
    }
  }
  cout << ret << "\n";
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}