#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, num;
vector<int> a, dp;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    a.push_back(num);
  }
  reverse(a.begin(), a.end());
}

void go() {
  for (auto x : a) {
    auto it = lower_bound(dp.begin(), dp.end(), x);
    if (it == dp.end()) {
      dp.push_back(x);
    } else {
      *it = x;
    }
  }
  cout << n - dp.size() << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}