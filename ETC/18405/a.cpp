#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

int n, k;
int a[204][204];
int s, x, y;
vector<pii> virus[1004];
queue<tiii> q;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j]) {
        virus[a[i][j]].push_back({i, j});
      }
    }
  }

  cin >> s >> x >> y;

  for (int i = 1; i <= k; i++) {
    for (auto it : virus[i]) {
      q.push({it.first, it.second, 0});
    }
  }
}

void go() {
  int currY, currX, currT;
  while (!q.empty()) {
    tie(currY, currX, currT) = q.front();
    q.pop();
    if (currT == s) {
      break;
    }
    for (int i = 0; i < 4; i++) {
      int ny = currY + dy[i];
      int nx = currX + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (a[ny][nx]) continue;

      a[ny][nx] = a[currY][currX];
      q.push({ny, nx, currT + 1});
    }
  }
  cout << a[x - 1][y - 1] << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}