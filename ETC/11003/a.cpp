#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

deque<pii> q;  // {i, num}

int n, l, num;

void init() { cin >> n >> l; }

void go() {
  for (int i = 0; i < n; i++) {
    cin >> num;

    if (!q.empty() && q.front().ff <= i - l) {
      q.pop_front();
    }

    while (!q.empty() && num < q.back().ss) {
      q.pop_back();
    }

    q.push_back({i, num});

    cout << q.front().ss << " ";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}