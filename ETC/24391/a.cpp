#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, i, j, prv, cur, ret;
int parent[100004];

void init() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

int findParent(int curr) {
  if (parent[curr] == curr) return curr;
  parent[curr] = findParent(parent[curr]);
  return parent[curr];
}

void go() {
  for (int _ = 0; _ < m; _++) {
    cin >> i >> j;
    int parent1 = findParent(i);
    int parent2 = findParent(j);
    if (parent1 != parent2) {
      parent[parent2] = parent1;
    }
  }

  for (int i = 1; i <= n; i++) {
    cin >> cur;
    if (i == 1) {
      prv = findParent(cur);
      continue;
    }
    int prvParent = findParent(prv);
    int curParent = findParent(cur);

    if (prvParent != curParent) {
      ret++;
      prv = curParent;
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