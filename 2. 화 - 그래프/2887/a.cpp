#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

typedef pair<int, int> pii;

bool cmp1(pii a, pii b) { return a.first < b.first; }
bool cmp2(pair<int, pii> a, pair<int, pii> b) { return a.first < b.first; }

int n, x, y, z, ret;
vector<pii> vx, vy, vz;
vector<pair<int, pii>> edges;
int parent[100004];

void init() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> z;
    vx.push_back({x, i});
    vy.push_back({y, i});
    vz.push_back({z, i});
  }

  sort(vx.begin(), vx.end(), cmp1);
  sort(vy.begin(), vy.end(), cmp1);
  sort(vz.begin(), vz.end(), cmp1);

  for (int i = 0; i < n - 1; i++) {
    edges.push_back(
        {vx[i + 1].first - vx[i].first, {vx[i].second, vx[i + 1].second}});
    edges.push_back(
        {vy[i + 1].first - vy[i].first, {vy[i].second, vy[i + 1].second}});
    edges.push_back(
        {vz[i + 1].first - vz[i].first, {vz[i].second, vz[i + 1].second}});
  }

  sort(edges.begin(), edges.end(), cmp2);

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

  if (rootA < rootB) {
    parent[rootB] = rootA;
  } else {
    parent[rootA] = rootB;
  }
}

void go() {
  for (auto it : edges) {
    if (find(it.second.first) != find(it.second.second)) {
      _union(it.second.first, it.second.second);
      ret += it.first;
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