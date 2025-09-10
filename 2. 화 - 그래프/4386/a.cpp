#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

double n, x, y, ret;
pair<double, double> a[104];
vector<tuple<double, double, double>> graph;
int parent[104];

double dist(pair<double, double> p1, pair<double, double> p2) {
  return pow(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2),
             0.5);
}

bool cmp(tuple<double, double, double> a, tuple<double, double, double> b) {
  return get<2>(a) < get<2>(b);
}

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    a[i] = {x, y};
    parent[i] = i;
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      graph.push_back({i, j, dist(a[i], a[j])});
    }
  }
  sort(graph.begin(), graph.end(), cmp);
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
  for (auto it : graph) {
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