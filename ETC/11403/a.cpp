#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

int n;
int a[104][104];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) a[i][j] = INF;
    }
  }
}

void go() {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == INF)
        cout << "0 ";
      else if (a[i][j] > 0)
        cout << "1 ";
    }
    cout << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}