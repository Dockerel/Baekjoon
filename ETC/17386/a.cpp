#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

using namespace std;

struct Point {
  ll x;
  ll y;
};

Point operator-(Point a, Point b) {
  Point c;
  c.x = a.x - b.x;
  c.y = a.y - b.y;
  return c;
}

Point points[4];

int ccw(Point v1, Point v2) {
  ll result = v1.x * v2.y - v1.y * v2.x;
  if (result < 0)
    return -1;
  else if (result > 0)
    return 1;
  else
    return 0;
}

void init() {
  for (int i = 0; i < 4; i++) {
    cin >> points[i].x >> points[i].y;
  }
  return;
}

void go() {
  int stat1 = ccw(points[0] - points[1], points[0] - points[2]);
  int stat2 = ccw(points[0] - points[1], points[0] - points[3]);
  int stat3 = ccw(points[2] - points[3], points[2] - points[0]);
  int stat4 = ccw(points[2] - points[3], points[2] - points[1]);

  if (stat1 * stat2 < 0 && stat3 * stat4 < 0)
    cout << "1\n";
  else
    cout << "0\n";
  return;
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}