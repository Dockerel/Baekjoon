#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, num;
int parent[204];
vector<int> plan;

int findParent(int curr) {
  if (parent[curr] == curr) return curr;
  parent[curr] = findParent(parent[curr]);
  return parent[curr];
}

void init() {
  cin >> n;
  cin >> m;

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> num;
      if (num) {
        int parent1 = findParent(i);
        int parent2 = findParent(j);
        if (parent1 < parent2) {
          parent[parent2] = parent1;
        } else {
          parent[parent1] = parent2;
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> num;
    plan.push_back(num);
  }
}

void go() {
  int prv = findParent(plan[0]);
  for (int i = 1; i < plan.size(); i++) {
    int curr = findParent(plan[i]);
    if (prv != curr) {
      cout << "NO\n";
      exit(0);
    }
    prv = curr;
  }
  cout << "YES\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}