#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int n, h;
vector<int> towers;

priority_queue<pii, vector<pii>, greater<pii>> pq;

void init() {
  cin >> n;
  towers.push_back(0);
  for (int _ = 0; _ < n; _++) {
    cin >> h;
    towers.push_back(h);
  }
}

void go() {
  vector<int> ret(n + 1, 0);

  for (int i = n; i > 0; i--) {
    int height = towers[i];
    while (!pq.empty()) {
      auto it = pq.top();

      if (height > it.first) {
        ret[it.second] = i;
        pq.pop();
      } else {
        break;
      }
    }
    pq.push({height, i});
  }

  for (int i = 1; i <= n; i++) {
    cout << ret[i] << " ";
  }
  cout << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}