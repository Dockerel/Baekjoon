#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int r, c, t, ret;

int a[54][54];
int spread[54][54];

queue<pii> dust;
int y, x;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

pii airCleaner, upAir, downAir;

void init() {
  cin >> r >> c >> t;
  airCleaner = {-1, -1};
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
      if (a[i][j] == -1 && airCleaner.ff == -1)
        airCleaner = {i, j};  // 공청기 위치 확인
    }
  }

  memset(spread, 0, sizeof(spread));

  upAir = airCleaner;
  downAir = {airCleaner.ff + 1, airCleaner.ss};

  ret = 0;
}

pii getNextUpAir(pii curr) {
  if (curr.ff == upAir.ff) {
    if (curr.ss == c - 1) return {curr.ff - 1, curr.ss};
    return {curr.ff, curr.ss + 1};
  }
  if (curr.ss == c - 1) {
    if (curr.ff == 0) return {curr.ff, curr.ss - 1};
    return {curr.ff - 1, curr.ss};
  }
  if (curr.ff == 0) {
    if (curr.ss == 0) return {curr.ff + 1, curr.ss};
    return {curr.ff, curr.ss - 1};
  }
  return {curr.ff + 1, curr.ss};
}

pii getNextDownAir(pii curr) {
  if (curr.ff == downAir.ff) {
    if (curr.ss == c - 1) return {curr.ff + 1, curr.ss};
    return {curr.ff, curr.ss + 1};
  }
  if (curr.ss == c - 1) {
    if (curr.ff == r - 1) return {curr.ff, curr.ss - 1};
    return {curr.ff + 1, curr.ss};
  }
  if (curr.ff == r - 1) {
    if (curr.ss == 0) return {curr.ff - 1, curr.ss};
    return {curr.ff, curr.ss - 1};
  }
  return {curr.ff - 1, curr.ss};
}

void go() {
  while (t > 0) {  // t초 동안
    t--;

    dust = {};
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (a[i][j] > 0) dust.push({i, j});  // 초기 먼지 위치 확인
      }
    }

    // 1. 미세먼지 확산(확산량은 spread 배열에 존재, 확산되고 남은 먼지량은
    // a에서 빼줘야 함, 공청기로는 확산 x)
    while (!dust.empty()) {
      tie(y, x) = dust.front();
      dust.pop();

      if (a[y][x] < 5) continue;

      int sprd = a[y][x] / 5;
      int cnt = 0;

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1) continue;
        cnt++;
        spread[ny][nx] += sprd;
      }

      a[y][x] -= (sprd * cnt);
    }

    // 2. 기존 배열 + 확산
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        a[i][j] += spread[i][j];
      }
    }
    memset(spread, 0, sizeof(spread));

    // 3. 공청기 순환(공청기로 들어간 먼지는 제거)
    // 위쪽 공청기
    pii curr, nxt;
    int _prev;

    curr = {upAir.ff, upAir.ss};
    _prev = 0;
    while (1) {
      nxt = getNextUpAir(curr);

      if (nxt.ff != upAir.ff || nxt.ss != upAir.ss) {
        swap(a[nxt.ff][nxt.ss], _prev);
        curr = nxt;
      } else {
        break;
      }
    }

    // 아래쪽 공청기
    curr = {downAir.ff, downAir.ss};
    _prev = 0;
    while (1) {
      nxt = getNextDownAir(curr);

      if (nxt.ff != downAir.ff || nxt.ss != downAir.ss) {
        swap(a[nxt.ff][nxt.ss], _prev);
        curr = nxt;
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      ret += a[i][j];
    }
  }
  cout << ret + 2 << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}