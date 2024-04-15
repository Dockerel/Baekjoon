#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    pair<int, int> temp;
    cin >> temp.first >> temp.second;
    v.push_back(temp);
  }
  return;
}
void go() {
  sort(v.begin(), v.end(), cmp);
  for (auto it : v) {
    cout << it.first << " " << it.second << "\n";
  }
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}

0 6
1 4
2 13
3 5
3 8
5 7
5 9
6 10
8 11
8 12
12 14
