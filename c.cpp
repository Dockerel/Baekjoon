#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, start, finish;
int _prev, ret;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
vector<pair<int, int>> v;
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> start >> finish;
    v.push_back({start, finish});
  }
  sort(v.begin(), v.end(), cmp);
  _prev = ret = 0;
  return;
}
void go() {
  for (auto it : v) {
    if (_prev <= it.first) {
      ret++;
      _prev = it.second;
    }
  }
  cout << ret << "\n";
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}