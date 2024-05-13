#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, ret = 0;
int col[15];

bool check(int level) {
  for (int i = 0; i < level; i++) {
    if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
      return false;
  }
  return true;
}

void go(int idx) {
  if (idx == n) {
    ret++;
    return;
  }
  for (int i = 0; i < n; i++) {
    col[idx] = i;
    if (check(idx)) go(idx + 1);
  }
}

int main() {
  fastIO;
  cin >> n;
  go(0);
  cout << ret << "\n";
  return 0;
}