#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
#define pii pair<int, int>
using namespace std;
int n, m, from, to, weight;
vector<pii> graph[504];
long long dist[504];
void init() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> from >> to >> weight;
    graph[from].push_back({to, weight});
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  dist[1] = 0;
}
int go() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[j] == INF) continue;
      for (int k = 0; k < graph[j].size(); k++) {
        pii temp = graph[j][k];
        if (dist[temp.first] > dist[j] + temp.second) {
          dist[temp.first] = dist[j] + temp.second;
          if (i == n) return 1;
        }
      }
    }
  }
  return 0;
}
int main() {
  fastIO;
  init();
  if (go()) {
    cout << "-1\n";
  } else {
    for (int i = 2; i <= n; i++) {
      cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
  }
  return 0;
}