#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, n1, n2, w;
long long maxw, ret;
int parent[100004];
vector<tuple<int, int, int>> edges;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<2>(a) < get<2>(b);
}

void init() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> n1 >> n2 >> w;
    edges.push_back({n1, n2, w});
  }
  sort(edges.begin(), edges.end(), cmp);
  ret = 0;
  maxw = -1;
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
      if (maxw < get<2>(it)) maxw = get<2>(it);
    }
  }
  cout << ret - maxw << "\n";
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}
