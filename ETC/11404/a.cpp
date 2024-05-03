#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int n, m, from, to, weight;
int a[104][104];

void init() {
  cin >> n;
  cin >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        a[i][j] = 0;
      else
        a[i][j] = INF;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> from >> to >> weight;
    a[from][to] = min(a[from][to], weight);
  }
  return;
}

void go() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == INF) a[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }

  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}