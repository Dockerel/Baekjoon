#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, n1, n2;

int parent[300004];

int find_parent(int child) {
  if (parent[child] == -1) return child;
  parent[child] = find_parent(parent[child]);
  return parent[child];
}

void init() {
  cin >> n;
  memset(parent, -1, sizeof(parent));
  for (int i = 0; i < n - 2; i++) {
    cin >> n1 >> n2;
    // n1의 parent 찾기
    // n2 parent 찾기
    int parent1 = find_parent(n1);
    int parent2 = find_parent(n2);
    parent[max(parent1, parent2)] = min(parent1, parent2);
  }
}

void go() {
  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) {
      cout << i << " ";
    }
  }
  cout << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}