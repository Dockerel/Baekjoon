#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
int t, n;
struct Point {
  ll x, y;
};
vector<Point> p;
int st[200004], top;
Point ret[2];
ll maxdist, d, _prev;
void push(int n) { st[top++] = n; }
void init() {
  p.clear();
  top = 0;
  maxdist = -1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    Point temp;
    cin >> temp.x >> temp.y;
    p.push_back(temp);
  }
}

ll ccw(Point a, Point b, Point c) {
  return (a.x * b.y + b.x * c.y + c.x * a.y) -
         (a.y * b.x + b.y * c.x + c.y * a.x);
}

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp1(Point a, Point b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
bool cmp2(Point a, Point b) {
  ll c = ccw(p[0], a, b);
  if (c == 0) {
    return dist(p[0], a) < dist(p[0], b);
  }
  return c > 0;
}

void go() {
  sort(p.begin(), p.end(), cmp1);
  sort(p.begin() + 1, p.end(), cmp2);

  push(0);
  push(1);
  for (int i = 2; i < n; i++) {
    while (top >= 2 && ccw(p[st[top - 2]], p[st[top - 1]], p[i]) <= 0) top--;
    push(i);
  }

  // for (int i = 0; i < top; i++) {
  //   _prev = 0;
  //   for (int j = (i + 1) % top;; j = (j + 1) % top) {
  //     if (i == j) break;

  //     d = dist(p[st[i]], p[st[j]]);

  //     if (maxdist < d) {
  //       ret[0] = p[i];
  //       ret[1] = p[j];
  //       maxdist = d;
  //     }

  //     if (_prev) {
  //       if (_prev > d) {
  //         break;
  //       }
  //     }

  //     _prev = d;
  //   }
  // }

  // cout << ret[0].x << " " << ret[0].y << " " << ret[1].x << " " << ret[1].y
  //      << "\n";
}

int main() {
  fastIO;
  cin >> t;
  while (t--) {
    init();
    go();
  }
  return 0;
}
