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

bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

bool operator<=(Point a, Point b) {
  if (a.x == b.x) return a.y <= b.y;
  return a.x <= b.x;
}

Point points[4];
int flag;

int ccw(Point v1, Point v2) {
  ll op = v1.x * v2.y - v1.y * v2.x;
  if (op > 0)
    return 1;
  else if (op < 0)
    return -1;
  else
    return 0;
}

double det(Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }

void init() {
  for (int i = 0; i < 4; i++) {
    cin >> points[i].x >> points[i].y;
  }
}

bool isIntersect() {
  int ret1 = ccw(points[1] - points[0], points[2] - points[0]) *
             ccw(points[1] - points[0], points[3] - points[0]);
  int ret2 = ccw(points[3] - points[2], points[0] - points[2]) *
             ccw(points[3] - points[2], points[1] - points[2]);
  if (ret1 <= 0 && ret2 <= 0) {
    if (ret1 == 0 && ret2 == 0) {
      if (points[1] <= points[0]) swap(points[0], points[1]);
      if (points[3] <= points[2]) swap(points[2], points[3]);
      if (points[0] <= points[3] && points[2] <= points[1]) {
        flag = 1;
        return true;
      } else {
        return false;
      }
    }
    flag = 1;
    return true;
  }
  return false;
}

void printIntersectionPoint() {
  double px = det(points[0], points[1]) * (points[2].x - points[3].x) -
              (points[0].x - points[1].x) * det(points[2], points[3]);
  double py = det(points[0], points[1]) * (points[2].y - points[3].y) -
              (points[0].y - points[1].y) * det(points[2], points[3]);
  double p = (points[0].x - points[1].x) * (points[2].y - points[3].y) -
             (points[0].y - points[1].y) * (points[2].x - points[3].x);

  if (p == 0) {
    if (points[1] == points[2])
      cout << points[1].x << " " << points[1].y << "\n";
    else if (points[3] == points[0])
      cout << points[0].x << " " << points[0].y << "\n";
  } else {
    cout << fixed;
    cout.precision(9);
    cout << px / p << " " << py / p << "\n";
  }
}

void go() {
  if (isIntersect()) {
    cout << "1\n";
    if (flag) {
      printIntersectionPoint();
    }
  } else {
    cout << "0\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}