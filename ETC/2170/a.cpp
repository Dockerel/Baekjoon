#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int n, st, ed, prev_st, prev_ed, ret;
priority_queue<pii, vector<pii>, greater<pii>> pq;

void init() {
  cin >> n;
  for (int _ = 0; _ < n; _++) {
    cin >> st >> ed;
    pq.push({st, ed});
  }
  ret = 0;

  tie(st, ed) = pq.top();
  pq.pop();
  prev_st = st, prev_ed = ed;
}

void go() {
  while (!pq.empty()) {
    tie(st, ed) = pq.top();
    pq.pop();
    // 전부다 st 기준으로 판단?
    if (st <= prev_ed) {
      // ed가 기존 범위 벗어나는 경우
      if (ed > prev_ed) {
        prev_ed = ed;
      }
      // 기존 범위에 포함되는 경우 -> continue
    } else {
      // st가 prev_ed보다 큰 경우
      ret += (prev_ed - prev_st);
      prev_st = st, prev_ed = ed;
    }
  }

  cout << ret + (prev_ed - prev_st) << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}