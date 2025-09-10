#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
  ll x, y;
};

int n;
char c;
Point tmp;

vector<Point> point;

ll ccw(Point a, Point b, Point c) {
  return (a.x * b.y + b.x * c.y + c.x * a.y) -
         (a.y * b.x + b.y * c.x + c.y * a.x);
}

bool cmp1(Point a, Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp2(Point a, Point b) {
  ll res = ccw(point[0], a, b);
  if (res != 0) {
    return res > 0;
  } else {
    return dist(point[0], a) < dist(point[0], b);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tmp.x >> tmp.y >> c;
    if (c == 'Y') {
      point.push_back(tmp);
    }
  }

  sort(point.begin(), point.end(), cmp1);
  sort(point.begin() + 1, point.end(), cmp2);

  int rev = point.size() - 1;
  for (int i = point.size() - 1; i >= 1; i--) {
    if (ccw(point[0], point[i], point[i - 1]) == 0) {
      rev = i - 1;
    } else {
      break;
    }
  }

  reverse(point.begin() + rev, point.end());

  cout << point.size() << "\n";
  for (auto it : point) {
    cout << it.x << " " << it.y << "\n";
  }

  return 0;
}