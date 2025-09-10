#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define MAX 804
#define INF 987654321

using namespace std;

int n, e;
int a, b, c;
int v1, v2;
int curr, curr_weight, nxt, nxt_weight;

int one2V1, one2V2;
int n2V1, n2V2;
int v12V2;

int ret;

vector<pii> graph[MAX];

priority_queue<pii, vector<pii>, greater<pii>> pq;
int visited[MAX];

void init() {
  cin >> n >> e;
  for (int _ = 0; _ < e; _++) {
    cin >> a >> b >> c;
    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }
  cin >> v1 >> v2;
  ret = INF;
}

void go(int weight, int start) {
  pq.push({weight, start});

  while (!pq.empty()) {
    tie(curr_weight, curr) = pq.top();
    pq.pop();

    for (auto it : graph[curr]) {
      tie(nxt_weight, nxt) = it;
      int temp_weight = curr_weight + nxt_weight;
      if (temp_weight < visited[nxt]) {
        visited[nxt] = temp_weight;
        pq.push({temp_weight, nxt});
      }
    }
  }
}

void initVisited(int start) {
  for (int i = 1; i <= n; i++) {
    if (i == start) {
      visited[i] = 0;
      continue;
    }
    visited[i] = INF;
  }
}

int main() {
  fastIO;
  init();

  // 1 -> v1, 1 -> v2
  initVisited(1);
  go(0, 1);
  one2V1 = visited[v1];
  one2V2 = visited[v2];

  // N -> v1, N -> v2
  initVisited(n);
  go(0, n);
  n2V1 = visited[v1];
  n2V2 = visited[v2];

  // v1 -> v2
  initVisited(v1);
  go(0, v1);
  v12V2 = visited[v2];

  if (v12V2 == INF) {
    cout << "-1";
    return 0;
  }

  // 1. 1 -> v1 -> v2 -> N
  if (one2V1 == INF || n2V2 == INF) {
    cout << "-1\n";
    return 0;
  }
  ret = min(ret, one2V1 + n2V2 + v12V2);

  // 2. 1 -> v2 -> v1 -> N
  if (one2V2 == INF || n2V1 == INF) {
    cout << "-1\n";
    return 0;
  }
  ret = min(ret, one2V2 + n2V1 + v12V2);

  cout << ret << "\n";

  return 0;
}