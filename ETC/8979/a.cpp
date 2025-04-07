#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tiii tuple<int, int, int>

using namespace std;

int n, k;

priority_queue<tiii, vector<tiii>, less<tiii>> pq;

int n1, n2, n3, n4;
tiii target;

int ret;

void init() {
  cin >> n >> k;
  for (int _ = 0; _ < n; _++) {
    cin >> n1 >> n2 >> n3 >> n4;
    if (n1 == k) {
      target = {n2, n3, n4};
    }
    pq.push({n2, n3, n4});
  }
}

bool equalsTarget(tiii curr) {
  int t1, t2, t3;
  tie(t1, t2, t3) = target;
  tie(n1, n2, n3) = curr;
  return t1 == n1 && t2 == n2 && t3 == n3;
}

void go() {
  ret = 1;
  while (!pq.empty()) {
    if (equalsTarget(pq.top())) {
      break;
    }
    pq.pop();
    ret++;
  }
  cout << ret << "\n";

  //   while (!pq.empty()) {
  //     tie(n1, n2, n3) = pq.top();
  //     pq.pop();
  //     cout << n1 << " " << n2 << " " << n3 << "\n";
  //   }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}