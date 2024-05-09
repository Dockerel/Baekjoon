#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1234987654321
#define MAX 100004
#define ll long long
#define pli pair<ll, int>

using namespace std;

int n, m, s, u, v, w;
int sight[MAX];
vector<pli> graph[MAX];
ll dist[MAX];

struct cmp {
  bool operator()(pli a, pli b) { return a.first > b.first; }
};

priority_queue<pli, vector<pli>, cmp> pq;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    sight[i] = s;
  }
  sight[n - 1] = 0;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    if (sight[u] || sight[v]) continue;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  for (int i = 0; i < n; i++) {
    dist[i] = INF;
  }
  dist[0] = 0;
  pq.push({0, 0});
}

void go() {
  while (!pq.empty()) {
    ll cur_dist = pq.top().first;
    int cur_node = pq.top().second;
    pq.pop();
    if (dist[cur_node] < cur_dist) continue;
    for (auto it : graph[cur_node]) {
      ll nxt_dist = it.second + cur_dist;
      int nxt_node = it.first;

      if (nxt_dist < dist[nxt_node]) {
        dist[nxt_node] = nxt_dist;
        pq.push({nxt_dist, nxt_node});
      }
    }
  }
  if (dist[n - 1] == INF)
    cout << "-1\n";
  else
    cout << dist[n - 1] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}