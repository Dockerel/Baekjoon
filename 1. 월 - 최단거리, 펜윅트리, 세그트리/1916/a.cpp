#include <bits/stdc++.h>
#define MAX 1004
#define INF 987654321
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
int n, m, A, B, val, min_node;
int start, dest;
int a[MAX][MAX], v[MAX], dist[MAX];

void init() {
  cin >> n;
  cin >> m;

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
    for (int j = 1; j <= n; j++) {
      if (i == j)
        a[i][j] = 0;
      else
        a[i][j] = INF;
    }
  }

  for (int i = 0; i < m; i++) {
    cin >> A >> B >> val;
    a[A][B] = min(a[A][B], val);
  }

  cin >> start >> dest;
  if (start == dest) {
    cout << 0 << "\n";
    exit(0);
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = a[start][i];
  }
  memset(v, 0, sizeof(v));
  v[start] = 1;
  return;
}

int getMinNode() {
  pair<int, int> ret = {0, INF};
  for (int i = 1; i <= n; i++) {
    if (!v[i] && dist[i] < ret.second) {
      ret.first = i;
      ret.second = dist[i];
    }
  }
  return ret.first;
}

void go() {
  while (1) {
    min_node = getMinNode();
    if (min_node == 0) break;

    v[min_node] = 1;
    for (int i = 1; i <= n; i++) {
      if (!v[i]) {
        dist[i] = min(dist[i], dist[min_node] + a[min_node][i]);
      }
    }
  }
  cout << dist[dest] << "\n";
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}