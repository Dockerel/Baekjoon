#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, k, p;
int heap[200004];
int curr, upCnt, downCnt;

void init() {
  cin >> n;
  cin >> k >> p;
}

void dfs(int here) {
  if (here > n) return;

  downCnt++;
  heap[here] = -1;

  dfs(here * 2);
  dfs(here * 2 + 1);
}

void go() {
  curr = p / 2;
  while (curr > 0) {
    upCnt++;
    heap[curr] = 1;
    curr /= 2;
  }

  dfs(p * 2);
  dfs(p * 2 + 1);

  if (upCnt >= k || downCnt > n - k) {
    cout << "-1\n";
    return;
  }

  int temp = upCnt + 1;
  upCnt = 1;
  downCnt = n;
  for (int i = 1; i <= n; i++) {
    if (i == p) {
      cout << k << "\n";
    } else if (heap[i] == 1) {
      cout << upCnt++ << "\n";
    } else if (heap[i] == 0) {
      if (temp == k) temp++;
      cout << temp++ << "\n";
    } else {
      cout << downCnt-- << "\n";
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}