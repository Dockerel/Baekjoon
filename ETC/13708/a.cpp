#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double x, double y) : x(x), y(y){};
};

int n, reps;
Point points[304];
double learning_rate;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }
  reps = 20000;  // 반복횟수
  learning_rate = 1;
  return;
}

Point getAveragePoint() {
  Point pt = Point(0, 0);
  for (int i = 0; i < n; i++) {
    pt.x += points[i].x;
    pt.y += points[i].y;
  }
  pt.x /= n;
  pt.y /= n;
  return pt;
}

double getDist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point getFarestPoint(Point curr) {
  Point pt = Point(curr.x, curr.y);
  for (int i = 0; i < n; i++) {
    if (getDist(points[i], curr) > getDist(pt, curr)) {
      pt = Point(points[i].x, points[i].y);
    }
  }
  return pt;
}

void go() {
  Point curr = getAveragePoint();  // 최소 와접원의 중심에 가까워짐

  for (int i = 0; i < reps; i++) {
    Point farPt = getFarestPoint(curr);
    curr.x += ((farPt.x - curr.x) * learning_rate);
    curr.y += ((farPt.y - curr.y) * learning_rate);
    learning_rate *= 0.999;
  }

  Point farPt = getFarestPoint(curr);
  cout << fixed;
  cout.precision(2);
  cout << sqrt(getDist(curr, farPt)) * 2 << "\n";
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}