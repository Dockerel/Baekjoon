#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, end;
vector<pair<int, int>> times;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    pair<int, int> tmp;
    cin >> tmp.first >> tmp.second;
    times.push_back(tmp);
  }
}

void go() {
  sort(times.begin(), times.end(), cmp);
  pq.push(times[0].second);

  for (int i = 1; i < times.size(); i++) {
    pq.push(times[i].second);
    if (pq.top() <= times[i].first) {
      pq.pop();
    }
  }

  cout << pq.size() << "\n";
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}