#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second
#define INF 987654321

using namespace std;

int n;
int a[104][104];
pair<pii, int> v[104][104];  // {{방문 여부, 땅 종류}, 놓은 다리 개수}

queue<pii> q;
queue<pii> bridge;

int y, x, cnt;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int ret;

void init() {
  ret = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      v[i][j] = {{0, -1}, 0};
    }
  }

  int curr = 0;
  int foundAtInit = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] && v[i][j].ff.ff == 0) {
        q.push({i, j});
        v[i][j] = {{1, curr}, 0};
        while (!q.empty()) {
          tie(y, x) = q.front();
          q.pop();

          for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (v[ny][nx].ff.ff) {
              // 땅이 바로 나와버림
              if (v[ny][nx].ff.ss != -1 && v[y][x].ff.ss != v[ny][nx].ff.ss) {
                foundAtInit = 1;
              }
              continue;
            }

            if (a[ny][nx] == 1) {
              v[ny][nx] = {{1, curr}, 0};
              q.push({ny, nx});
            } else {
              v[ny][nx] = {{1, curr}, 1};
              bridge.push({ny, nx});
            }
          }
        }
        curr++;
      }
    }
  }

  // 1 짜리 다리 처리
  if (foundAtInit) {
    cout << "1\n";
    exit(0);
  }
}

void go() {
  while (!bridge.empty()) {
    tie(y, x) = bridge.front();
    bridge.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if (v[ny][nx].ff.ff == 1) {
        // 땅이 나와버림
        if (v[ny][nx].ff.ss != -1 && v[y][x].ff.ss != v[ny][nx].ff.ss) {
          ret = min(ret, v[y][x].ss + v[ny][nx].ss);
        }
        continue;
      }

      if (a[ny][nx] == 0) {
        bridge.push({ny, nx});
        v[ny][nx] = {{1, v[y][x].ff.ss}, v[y][x].ss + 1};
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}