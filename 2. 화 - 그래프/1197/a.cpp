#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int v, e, n1, n2, w, ret;
vector<tuple<int, int, int>> edges;
int parent[10004];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<2>(a) < get<2>(b);
}

void init() {
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    cin >> n1 >> n2 >> w;
    edges.push_back({n1, n2, w});
  }
  sort(edges.begin(), edges.end(), cmp);
  for (int i = 1; i <= v; i++) {
    parent[i] = i;
  }
  ret = 0;
  return;
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
  return;
}

void go() {
  for (auto it : edges) {
    if (find(get<0>(it)) != find(get<1>(it))) {
      _union(get<0>(it), get<1>(it));
      ret += get<2>(it);
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