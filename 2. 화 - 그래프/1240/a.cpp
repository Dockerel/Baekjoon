#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, m;
int n1, n2, w;
vector<pii> graph[1004];
int v[1004];

queue<pii> q;
int curr, cnt;

void init() {
  cin >> n >> m;
  for (int _ = 0; _ < n - 1; _++) {
    cin >> n1 >> n2 >> w;
    graph[n1].push_back({n2, w});
    graph[n2].push_back({n1, w});
  }
}

void go() {
  cin >> n1 >> n2;
  memset(v, 0, sizeof(v));
  v[n1] = 1;
  q.push({n1, 0});
  while (!q.empty()) {
    tie(curr, cnt) = q.front();
    q.pop();

    if (curr == n2) {
      cout << cnt << "\n";
      break;
    }

    for (auto it : graph[curr]) {
      if (v[it.ff]) continue;
      v[it.ff] = 1;
      q.push({it.ff, cnt + it.ss});
    }
  }

  while (!q.empty()) q.pop();
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < m; _++) {
    go();
  }
  return 0;
}