#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
int v[2][500004];

int dist(int n) { return (n * (n + 1)) / 2; }

void go(int x, int t) {
  queue<pair<int, int>> Q;
  Q.push({x, t});
  v[0][x] = t;

  while (!Q.empty()) {
    tie(x, t) = Q.front();
    Q.pop();

    int tmp = k + dist(t);
    if (v[t % 2][tmp]) {
      cout << t << "\n";
      return;
    }
    if (tmp > 500000) {
      cout << "-1\n";
      return;
    }

    int dx[3] = {x + 1, x - 1, x * 2};
    for (int i = 0; i < 3; i++) {
      if (dx[i] >= 0 && dx[i] <= 500000 && !v[(t + 1) % 2][dx[i]]) {
        v[(t + 1) % 2][dx[i]] = t + 1;
        Q.push({dx[i], t + 1});
      }
    }
  }
}
int main() {
  cin >> n >> k;
  if (n == k) {
    cout << "0\n";
    exit(0);
  }
  memset(v, 0, sizeof(v));
  go(n, 0);

  return 0;
}