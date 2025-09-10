#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

struct Point {
  double x, y;
  Point() : x(0), y(0){};
  Point(double x, double y) : x(x), y(y){};
};

int n, reps;
double learning_rate;
Point pts[1004];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  reps = 20000;
  learning_rate = 1;
}

Point getAveragePt() {
  Point pt = Point();
  for (int i = 0; i < n; i++) {
    pt.x += pts[i].x;
    pt.y += pts[i].y;
  }
  pt.x /= n;
  pt.y /= n;
  return pt;
}

double getDist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point getFarPt(Point currPt) {
  Point pt = Point(currPt.x, currPt.y);
  for (int i = 0; i < n; i++) {
    if (getDist(currPt, pts[i]) > getDist(currPt, pt)) {
      pt = Point(pts[i].x, pts[i].y);
    }
  }
  return pt;
}

void go() {
  Point currPt = getAveragePt();
  for (int _ = 0; _ < reps; _++) {
    Point farPt = getFarPt(currPt);
    currPt.x += ((farPt.x - currPt.x) * learning_rate);
    currPt.y += ((farPt.y - currPt.y) * learning_rate);
    learning_rate *= 0.999;
  }

  Point farPt = getFarPt(currPt);
  double dist = getDist(currPt, farPt);
  cout << fixed;
  cout.precision(3);
  cout << currPt.x << " " << currPt.y << "\n";
  cout << sqrt(dist) << "\n";
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}