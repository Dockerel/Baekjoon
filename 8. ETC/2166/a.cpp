#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
int n;
vector<Point> points;
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    Point temp;
    cin >> temp.x >> temp.y;
    points.push_back(temp);
  }
}
double ccw(Point p1, Point p2, Point p3) {
  Point v1 = p2 - p1;
  Point v2 = p3 - p1;
  double s = v1.x * v2.y - v2.x * v1.y;
  return s / 2;
}
void go() {
  double ret = 0.0;
  for (int i = 1; i < n - 1; i++) {
    ret += ccw(points[0], points[i], points[i + 1]);
  }
  cout << fixed;
  cout.precision(1);
  cout << abs(ret) << "\n";
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}