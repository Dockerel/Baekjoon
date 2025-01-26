#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int x, ret;

void init() {
  cin >> x;
  ret = 0;
}

void go() {
  for (int i = 0; true; i++) {
    if ((1 << i) > x) break;
    if (x & (1 << i)) ret++;
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}