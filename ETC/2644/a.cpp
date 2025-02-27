#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, n1, n2, m;
int parent, child;
int curr, cnt;

vector<int> graph[104];
int v[104];

void init() {
  cin >> n;
  cin >> parent >> child;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> n1 >> n2;
    graph[n1].push_back(n2);
    graph[n2].push_back(n1);
  }
}

void go() {
  int printed = 0;
  queue<pair<int, int>> q;
  q.push({parent, 0});
  v[parent] = 1;
  while (!q.empty()) {
    tie(curr, cnt) = q.front();
    q.pop();

    if (curr == child) {
      cout << cnt << "\n";
      printed = 1;
      break;
    }

    for (auto it : graph[curr]) {
      if (v[it]) continue;
      v[it] = 1;
      q.push({it, cnt + 1});
    }
  }

  if (!printed) {
    cout << "-1\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}