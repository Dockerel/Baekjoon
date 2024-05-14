#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

using namespace std;

struct Point {
  ll x;
  ll y;
};

int n;
int ret[2004][2004];
vector<Point> points;

Point operator-(Point a, Point b) {
  Point c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  return c;
}

bool operator<=(Point a, Point b) {
  if (a.x == b.x) return a.y <= b.y;
  return a.x <= b.x;
}

bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }
bool operator!=(Point a, Point b) { return a.x != b.x || a.y != b.y; }

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      Point temp;
      cin >> temp.x >> temp.y;
      points.push_back(temp);
    }
  }
  memset(ret, 0, sizeof(ret));
}

int ccw(Point v1, Point v2) {
  ll op = v1.x * v2.y - v2.x * v1.y;
  if (op < 0)
    return -1;
  else if (op > 0)
    return 1;
  else
    return 0;
}

int isIntersect(pair<Point, Point> pts1, pair<Point, Point> pts2) {
  int ccw1 = ccw(pts1.second - pts1.first, pts2.first - pts1.first);
  int ccw2 = ccw(pts1.second - pts1.first, pts2.second - pts1.first);
  int ccw3 = ccw(pts2.second - pts2.first, pts1.first - pts2.first);
  int ccw4 = ccw(pts2.second - pts2.first, pts1.second - pts2.first);

  int stat1 = ccw1 * ccw2;
  int stat2 = ccw3 * ccw4;

  // 교점이 하나거나 무한히 많이 있음 - 1, 2, 3
  if (stat1 <= 0 && stat2 <= 0) {
    // 교점이 정확히 하나 있으며, 그 교점이 어느 선분의 끝점도 아님 - 2
    if (stat1 < 0 && stat2 < 0) {
      return 2;
    } else if (abs(ccw1) | abs(ccw2)) {  // 교점이 정확히 하나 있으며, 그
                                         // 교점이 적어도 한 선분의 끝점임 - 1
      return 1;
    } else {  // 한 직선위에 모든 점이 존재하면서 0,1,3 판별
      if (pts1.second <= pts1.first) swap(pts1.first, pts1.second);
      if (pts2.second <= pts2.first) swap(pts2.first, pts2.second);

      // 무한히 많거나 하나거나
      if (pts1.first <= pts2.second && pts2.first <= pts1.second) {
        if ((pts1.first == pts2.second && pts1.second != pts2.first) ||
            (pts1.second == pts2.first && pts1.first != pts2.second))
          return 1;
        else
          return 3;
      } else {
        return 0;
      }
    }
  } else {
    // 교점이 없음 - 0
    return 0;
  }
}

void go() {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        ret[i][j] = ret[j][i] = 3;
        continue;
      }
      ret[i][j] = ret[j][i] = isIntersect({points[i * 2], points[i * 2 + 1]},
                                          {points[j * 2], points[j * 2 + 1]});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ret[i][j];
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