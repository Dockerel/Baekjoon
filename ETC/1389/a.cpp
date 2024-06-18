#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 10000

using namespace std;

int n, m, n1, n2;
int a[104][104];
pair<int, int> ret;

void init() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        a[i][j] = 0;
      else
        a[i][j] = INF;
    }
  }

  for (int _ = 0; _ < m; _++) {
    cin >> n1 >> n2;
    a[n1][n2] = a[n2][n1] = 1;
  }

  ret = {0, INF};
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
    int temp = 0;
    for (int j = 1; j <= n; j++) {
      temp += a[i][j];
    }
    if (temp < ret.second) {
      ret = {i, temp};
    }
  }
  cout << ret.first << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}