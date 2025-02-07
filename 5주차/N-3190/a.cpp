#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int n, k, l;
int y, x;
int ny, nx;
// 사과
int a[104][104];
int t;
char d;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

// 가야하는 방향
char dir[10004];  // 0: 직진, L: 좌회전, D: 우회전
int curr;         // 현재 초
int currDir;      // 현재 방향, 0:위쪽, 1:오른쪽, 2:아래쪽, 3: 왼쪽
// 뒤에서 빼서 삽입(뱀)
queue<pii> q;
// 뒤에서 뺀거 삽입전 맨 앞에 있던 머리 위치
pii prevFront;

int body[104][104];

void init() {
  cin >> n;
  cin >> k;

  memset(a, 0, sizeof(a));
  memset(body, 0, sizeof(body));
  memset(dir, 0, sizeof(dir));

  for (int _ = 0; _ < k; _++) {
    cin >> y >> x;
    a[y][x] = 1;
  }

  cin >> l;
  for (int _ = 0; _ < l; _++) {
    cin >> t >> d;
    dir[t] = d;
  }

  // 초기 상태
  curr = 0;
  currDir = 1;
  q.push({1, 1});
  prevFront = {1, 1};
  body[1][1] = 1;
}

void go() {
  // 초 +1 시키고
  // 직진 시키는데 : 충돌 확인
  // 사과 있는지 확인하고
  // 있으면 큐에서 빼지말고 사과만 제거
  // 없으면 큐에서 빼서 진행방향에 붙여주기
  // 턴 해야하는지 확인 (dir 배열 확인)

  // 자기 자신과 부딛히는지 확인해야 할거 같음

  while (true) {
    curr += 1;

    tie(y, x) = prevFront;
    // 현재 바라보고 있는 방향 및 진행방향 고려해서
    ny = y + dy[currDir];
    nx = x + dx[currDir];

    // 진행방향만 고려한 것
    if (ny < 1 || ny > n || nx < 1 || nx > n) break;
    // 자기 몸도 고려 해줘야 함
    if (body[ny][nx] == 1) break;

    q.push({ny, nx});
    prevFront = {ny, nx};
    body[ny][nx] = 1;

    if (a[ny][nx] == 1) {
      a[ny][nx] = 0;
    } else {
      tie(y, x) = q.front();
      q.pop();
      body[y][x] = 0;
    }

    if (dir[curr] != 0) {
      if (dir[curr] == 'L') {
        currDir = (currDir + 3) % 4;
      } else if (dir[curr] == 'D') {
        currDir = (currDir + 1) % 4;
      }
    }
  }

  cout << curr << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}