#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int t, n, y, x, currN;
pii from, to, curr;

int visited[304][304];
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void init() { cin >> t; }

void go() {
  memset(visited, 0, sizeof(visited));
  cin >> n;
  cin >> y >> x;
  visited[y][x] = 1;
  from = {y, x};
  cin >> y >> x;
  to = {y, x};

  if (from.first == to.first && from.second == to.second) {
    cout << "0\n";
    return;
  }

  queue<pair<pii, int>> q;
  q.push({from, 0});

  while (!q.empty()) {
    tie(curr, currN) = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int ny = dy[i] + curr.first;
      int nx = dx[i] + curr.second;
      if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
      visited[ny][nx] = 1;
      if (ny == to.first && nx == to.second) {
        cout << currN + 1 << "\n";
        return;
      }
      q.push({{ny, nx}, currN + 1});
    }
  }
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < t; _++) {
    go();
  }
  return 0;
}