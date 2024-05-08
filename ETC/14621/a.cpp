#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, u, v, d, node, ret;
char univ_type;
int univ_types[1004];
int parent[1004];
vector<pair<int, pair<int, int>>> edges;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first < b.first;
}

void init() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> univ_type;
    if (univ_type == 'M') {
      univ_types[i] = 0;
    } else {
      univ_types[i] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> d;
    if (univ_types[u] != univ_types[v]) {
      edges.push_back({d, {u, v}});
    }
  }
  sort(edges.begin(), edges.end(), cmp);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  node = 1;
  ret = 0;
}

int find(int here) {
  if (parent[here] == here) return here;
  parent[here] = find(parent[here]);
  return parent[here];
}

void _union(int a, int b) {
  int rootA = find(a);
  int rootB = find(b);

  if (rootA < rootB)
    parent[rootB] = rootA;
  else
    parent[rootA] = rootB;
}

void go() {
  for (auto it : edges) {
    if (find(it.second.first) != find(it.second.second)) {
      _union(it.second.first, it.second.second);
      ret += it.first;
      node++;
    }
  }
  if (node == n)
    cout << ret << "\n";
  else
    cout << "-1\n";
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}