#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int m, n, x, y, z, total_cost, selected_cost;
vector<tuple<int, int, int>> edges;
int parent[200004];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<2>(a) < get<2>(b);
}

void init() {
  total_cost = 0;
  selected_cost = 0;
  edges.clear();
  for (int i = 0; i < m; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    edges.push_back({x, y, z});
    total_cost += z;
  }
  sort(edges.begin(), edges.end(), cmp);
  return;
}

int find(int here) {
  if (parent[here] == here) return here;
  parent[here] = find(parent[here]);
  return parent[here];
}

void _union(int a, int b) {
  int rootA = parent[a];
  int rootB = parent[b];
  if (rootA < rootB)
    parent[rootB] = rootA;
  else
    parent[rootA] = rootB;
  return;
}

void go() {
  for (auto it : edges) {
    if (find(get<0>(it)) != find(get<1>(it))) {
      _union(get<0>(it), get<1>(it));
      selected_cost += get<2>(it);
    }
  }
  cout << total_cost - selected_cost << "\n";
  return;
}

int main() {
  fastIO;
  while (1) {
    cin >> m >> n;
    if (!m && !n) break;
    init();
    go();
  }
  return 0;
}