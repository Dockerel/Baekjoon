#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define MAX 1004
#define INF 987654321

using namespace std;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int n, m, x, ret;
int n1, n2, w;
vector<pii> graph[MAX];
vector<pii> r_graph[MAX];

int _dist[MAX];
int _rdist[MAX];

int curr, curr_weight;
int nxt, nxt_weight;

void init() {
  cin >> n >> m >> x;
  for (int _ = 0; _ < m; _++) {
    cin >> n1 >> n2 >> w;
    graph[n1].push_back({n2, w});
    r_graph[n2].push_back({n1, w});
  }
  for (int i = 1; i <= n; i++) {
    _dist[i] = _rdist[i] = INF;
  }
  _dist[x] = _rdist[x] = 0;
  ret = 0;
}

void dijkstra(int type) {
  while (!pq.empty()) pq.pop();

  pq.push({x, 0});

  while (!pq.empty()) {
    tie(curr, curr_weight) = pq.top();
    pq.pop();

    for (auto it : (type == 0 ? graph[curr] : r_graph[curr])) {
      tie(nxt, nxt_weight) = it;
      int temp_weight = curr_weight + nxt_weight;
      if (temp_weight < (type == 0 ? _dist[nxt] : _rdist[nxt])) {
        (type == 0 ? _dist[nxt] : _rdist[nxt]) = temp_weight;
        pq.push({nxt, temp_weight});
      }
    }
  }
}

void go() {
  // graph로 다익스트라
  dijkstra(0);

  // r_graph로 다익스트라
  dijkstra(1);

  for (int i = 1; i <= n; i++) {
    ret = max(ret, _dist[i] + _rdist[i]);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}