#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, k;
int m, v, c;
unsigned long long ret;

vector<pii> jewels;
vector<int> bags;

priority_queue<int, vector<int>, less<int>> pq;

void init() {
  cin >> n >> k;
  for (int _ = 0; _ < n; _++) {
    cin >> m >> v;
    jewels.push_back({m, v});
  }
  sort(jewels.begin(), jewels.end());
  for (int i = 0; i < k; i++) {
    cin >> c;
    if (c > 1000000) c = 1000000;
    bags.push_back(c);
  }
  sort(bags.begin(), bags.end());
  ret = 0;
}

void go() {
  int idx = 0;
  for (int bag : bags) {
    for (int i = idx; i < n; i++) {
      tie(m, v) = jewels[i];
      if (m <= bag) {
        pq.push(v);
        idx++;
        continue;
      }
      break;
    }
    if (!pq.empty()) {
      ret += pq.top();
      pq.pop();
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