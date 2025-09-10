#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, n1, n2, ret;
vector<pii> v;
priority_queue<int, vector<int>, greater<int>> pq;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> n1 >> n2;
    v.push_back({n1, n2});
  }
  sort(v.begin(), v.end());
  ret = 0;
}

void go() {
  for (auto it : v) {
    pq.push(it.ss);
    if (pq.size() > it.ff) {
      pq.pop();
    }
  }

  while (!pq.empty()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}