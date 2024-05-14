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

Point points[3];

void init() {
  for (int i = 0; i < 3; i++) {
    Point temp;
    cin >> temp.x >> temp.y;
    points[i] = temp;
  }
}

int ccw(Point v1, Point v2) {
  ll op = v1.x * v2.y - v2.x * v1.y;
  if (op > 0)
    return 1;
  else if (op < 0)
    return -1;
  else
    return 0;
}

void go() { cout << ccw(points[1] - points[0], points[2] - points[0]) << "\n"; }

int main() {
  fastIO;

  init();
  go();

  return 0;
}