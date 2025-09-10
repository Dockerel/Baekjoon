#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
  bool operator<(const Point &a) const { return y == a.y ? x < a.x : y < a.y; }
};

int n;
Point p[100004];

int st[100004], top;
void push(int n) { st[top++] = n; }

ll ccw(Point &a, Point &b, Point &c) {  // a-b, a-c
  return a.x * b.y + b.x * c.y + c.x * a.y -
         (a.y * b.x + b.y * c.x + c.y * a.x);
}

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(Point &a, Point &b) {
  ll c = ccw(p[0], a, b);
  if (c == 0) {
    return dist(p[0], a) < dist(p[0], b);
  }
  return c > 0;  // p_0b가 p_0a보다 왼쪽에 있으면 그대로(시계 반대방향으로 sort)
}

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }

  sort(p, p + n);           // y 기준 sort
  sort(p + 1, p + n, cmp);  // 반시계방향 정렬
}

void go() {
  push(0);
  push(1);
  for (int i = 2; i < n; i++) {
    while (top >= 2 && ccw(p[st[top - 2]], p[st[top - 1]], p[i]) <=
                           0)  // ac가 ab의 반시계방향에 있으면 0보다 큰값,
                               // 시계방향에 있으면 0보다 작은값
      top--;  // 시계 반대방향 or 선상위에 있으면 pop()
    push(i);
  }
  cout << top;
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}

// Graham scan