#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 300004
#define INF 987654321
#define pii pair<int, int>

using namespace std;

int n, m, k, x;
int a, b;
int curr, curr_weight, nxt, nxt_weight;

vector<int> graph[MAX];
int _dist[MAX];

priority_queue<pii, vector<pii>, greater<pii>> pq;

void init() {
  cin >> n >> m >> k >> x;
  for (int _ = 0; _ < m; _++) {
    cin >> a >> b;
    graph[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    _dist[i] = INF;
  }
  _dist[x] = 0;
}

void dijkstra(int start) {
  pq.push({start, 0});

  while (!pq.empty()) {
    tie(curr, curr_weight) = pq.top();
    pq.pop();

    for (auto it : graph[curr]) {
      tie(nxt, nxt_weight) = make_pair(it, 1);
      int temp_weight = curr_weight + nxt_weight;
      if (temp_weight < _dist[nxt]) {
        _dist[nxt] = temp_weight;
        pq.push({nxt, temp_weight});
      }
    }
  }
}

void go() {
  dijkstra(x);

  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (_dist[i] == k) {
      ret++;
      cout << i << "\n";
    }
  }
  if (ret == 0) {
    cout << "-1\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}