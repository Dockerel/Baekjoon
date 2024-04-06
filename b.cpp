#include <bits/stdc++.h>
using namespace std;
int n;
struct Point {
  int x, y;
};
vector<Point> v;
bool cmp(Point a, Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    Point temp;
    cin >> temp.x >> temp.y;
    v.push_back(temp);
  }
  sort(v.begin(), v.end(), cmp);
  for (int i = 0; i < n; i++) {
    cout << v[i].x << " " << v[i].y << "\n";
  }
  return 0;
}