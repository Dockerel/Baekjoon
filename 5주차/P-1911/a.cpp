#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, l;
int st, ed;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int curr, ret;

void init() {
  cin >> n >> l;
  for (int _ = 0; _ < n; _++) {
    cin >> st >> ed;
    pq.push({st, ed});
  }
  curr = pq.top().ff;
}

void go() {
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();

    while (curr < it.ss) {
      curr += l;
      ret += 1;
    }

    while (!pq.empty()) {
      auto nxt = pq.top();
      if (curr < nxt.ff) {
        curr = nxt.ff;
        break;
      } else if (nxt.ss < curr) {
        pq.pop();
        continue;
      } else {
        break;
      }
    }
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}