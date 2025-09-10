#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int v, e, n1, n2, w, ret, cnt;
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
  ret = cnt = 0;
  return;
}

void go() {
  pq.push({1, 0});
  while (cnt < v) {
    auto temp = pq.top();
    pq.pop();
    int node, weight;
    node = temp.first;
    weight = temp.second;
    if (visited[node]) continue;
    visited[node] = 1;
    ret += weight;
    cnt++;
    for (auto it : graph[node]) {
      pq.push(it);
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