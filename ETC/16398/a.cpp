#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, w;
long long ret = 0;
vector<tuple<int, int, int>> edges;
int parent[1004];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<2>(a) < get<2>(b);
}

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> w;
      if (i < j) {
        edges.push_back({i, j, w});
      }
    }
  }
  sort(edges.begin(), edges.end(), cmp);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
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
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}