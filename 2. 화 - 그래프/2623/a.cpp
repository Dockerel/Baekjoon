#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
int num, node, _prev;

set<int> graph[1004];
int degree[1004];

queue<int> q;

vector<int> ret;

void init() {
  memset(degree, 0, sizeof(degree));

  cin >> n >> m;
  for (int _ = 0; _ < m; _++) {
    cin >> num;
    for (int i = 0; i < num; i++) {
      cin >> node;
      if (i != 0) {
        int prev_size = graph[_prev].size();
        graph[_prev].insert(node);
        if (prev_size != graph[_prev].size()) {
          degree[node] += 1;
        }
      }
      _prev = node;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (degree[i] == 0) {
      q.push(i);
    }
  }
}

void go() {
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    ret.push_back(curr);

    for (auto it : graph[curr]) {
      degree[it] -= 1;
      if (degree[it] == 0) q.push(it);
    }
  }

  if (ret.size() != n) {
    cout << "0\n";
    return;
  }

  for (auto it : ret) {
    cout << it << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}