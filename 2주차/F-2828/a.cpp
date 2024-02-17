#include <bits/stdc++.h>
using namespace std;
int n, m, j, loc, tmp, ret = 0;
int lft, rgt;
void getApple() {
  if (lft <= loc && rgt >= loc)
    return;
  else if (lft > loc) {
    tmp = lft - loc;
    ret += tmp;
    lft -= tmp;
    rgt -= tmp;
  } else if (rgt < loc) {
    tmp = loc - rgt;
    ret += tmp;
    lft += tmp;
    rgt += tmp;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  cin >> j;
  lft = 1;
  rgt = m;
  for (int i = 0; i < j; i++) {
    cin >> loc;
    getApple();
  }
  cout << ret << "\n";
  return 0;
}