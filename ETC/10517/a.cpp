#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, t;
struct Point {
  double x, y;
  Point() : x(0), y(0){};
  Point(double x, double y) : x(x), y(y){};
};
Point pts[3];
double learning_rate;

void init() {
  for (int i = 0; i < 3; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  learning_rate = 1;
}

Point getAveragePt() {
  Point pt = Point(0, 0);
  for (int i = 0; i < 3; i++) {
    pt.x += pts[i].x;
    pt.y += pts[i].y;
  }
  pt.x /= 3;
  pt.y /= 3;
  return pt;
}

double getDist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point getFarPt(Point currPt) {
  Point pt = Point(currPt.x, currPt.y);
  for (int i = 0; i < 3; i++) {
    if (getDist(currPt, pts[i]) > getDist(currPt, pt)) {
      pt = Point(pts[i].x, pts[i].y);
    }
  }
  return pt;
}

void go(int idx) {
  Point currPt = getAveragePt();
  for (int _ = 0; _ < 20000; _++) {
    Point farPt = getFarPt(currPt);
    currPt.x += (farPt.x - currPt.x) * learning_rate;
    currPt.y += (farPt.y - currPt.y) * learning_rate;
    learning_rate *= 0.999;
  }
  cout << fixed;
  cout.precision(2);
  cout << "Case #" << idx << ": " << currPt.x << " " << currPt.y << "\n";
}

int main() {
  fastIO;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    init();
    go(i);
  }
  return 0;
}