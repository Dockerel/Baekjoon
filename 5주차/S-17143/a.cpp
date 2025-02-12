#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tiii tuple<int, int, int>
#define tiiiii tuple<int, int, int, int, int>

using namespace std;

int a[104][104];
int R, C, M;
int r, c, s, d, z;
// d : 1234(위아래오른쪽왼쪽)
optional<tiii> sharks[104][104];

priority_queue<tiiiii, vector<tiiiii>, less<tiiiii>> pq;
int yy, xx;
int ret;

void init() {
  cin >> R >> C >> M;
  for (int i = 0; i < M; i++) {
    cin >> r >> c >> s >> d >> z;
    sharks[r][c] = tiii({z, s, d});
  }
  ret = 0;
}

tuple<int, int, int> move_shark(int speed, int dir, int y, int x) {
  if (dir == 1 || dir == 2) {  // 위 또는 아래 방향
    int cycle = (R - 1) * 2;
    int move = speed % cycle;
    for (int i = 0; i < move; ++i) {
      if (dir == 1 && y == 1)
        dir = 2;
      else if (dir == 2 && y == R)
        dir = 1;
      y += (dir == 1) ? -1 : 1;
    }
  } else if (dir == 3 || dir == 4) {  // 오른쪽 또는 왼쪽 방향
    int cycle = (C - 1) * 2;
    int move = speed % cycle;
    for (int i = 0; i < move; ++i) {
      if (dir == 4 && x == 1)
        dir = 3;
      else if (dir == 3 && x == C)
        dir = 4;
      x += (dir == 4) ? -1 : 1;
    }
  }
  return {dir, y, x};
}

void go() {
  // 낚시꾼은 0 - n+1에 존재(낚시는 1~n)
  // 낚시
  // 상어 이동
  // 상어 잡아먹기
  for (int i = 1; i <= C; i++) {
    // 낚시
    for (int j = 1; j <= R; j++) {
      if (sharks[j][i].has_value()) {
        tie(z, s, d) = sharks[j][i].value();
        ret += z;
        sharks[j][i].reset();
        break;
      }
    }
    // 상어 이동 + 잡아먹기
    while (!pq.empty()) pq.pop();
    for (int y = 1; y <= R; y++) {
      for (int x = 1; x <= C; x++) {
        if (sharks[y][x].has_value()) {
          pq.push(tuple_cat(sharks[y][x].value(), make_tuple(y, x)));
        }
        sharks[y][x].reset();
      }
    }

    while (!pq.empty()) {
      tie(z, s, d, yy, xx) = pq.top();
      pq.pop();

      // 이동
      int nd, ny, nx;
      tie(nd, ny, nx) = move_shark(s, d, yy, xx);
      if (!sharks[ny][nx].has_value()) {
        sharks[ny][nx] = {z, s, nd};
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