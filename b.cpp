#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
#define pii pair<int, int>
using namespace std;
int n, m, from, to, weight;
vector<pii> graph[504];
long long dist[504];
long long temp_dist[504];
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
void go() {
  for (int i = 1; i <= n; i++) {
    for (int ii = 1; ii <= n; ii++) {
      cout << (dist[ii] == INF ? "INF" : to_string(dist[ii])) << " ";
    }
    cout << "\n";

    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < graph[j].size(); k++) {
        pii temp = graph[j][k];
        if (dist[temp.first] == INF) {
          temp_dist[temp.first] = INF;
          continue;
        }
        temp_dist[j] = min(dist[j], dist[temp.first] + temp.second);
      }

      for (int l = 1; l <= n; l++) {
        dist[l] = temp_dist[l];
      }
    }
  }
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}