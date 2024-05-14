#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

struct Point {
  double x, y;
  Point() : x(0), y(0){};
  Point(double x, double y) : x(x), y(y){};
};

int n;
Point pts[104];
double learning_rate;
int reps;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  reps = 20000;
  learning_rate = 1;
}

Point getAveragePt() {
  Point pt = Point(0, 0);
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

Point getFarestPt(Point curr) {
  Point pt = Point(curr.x, curr.y);
  for (int i = 0; i < n; i++) {
    if (getDist(curr, pts[i]) > getDist(curr, pt)) {
      pt = Point(pts[i].x, pts[i].y);
    }
  }
  return pt;
}

void go() {
  Point curr = getAveragePt();
  for (int i = 0; i < reps; i++) {
    Point farPt = getFarestPt(curr);
    curr.x += ((farPt.x - curr.x) * learning_rate);
    curr.y += ((farPt.y - curr.y) * learning_rate);
    learning_rate *= 0.999;
  }
  Point farPt = getFarestPt(curr);
  cout.precision(11);
  cout << curr.x << " " << curr.y << " " << sqrt(getDist(farPt, curr)) << "\n";
  return;
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}