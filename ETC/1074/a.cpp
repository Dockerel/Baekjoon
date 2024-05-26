#include <bits/stdc++.h>
using namespace std;
int n, r, c;
int ret = 0;
void go(int x, int y, int size) {
  if (x == c && y == r) {
    cout << ret << "\n";
    exit(0);
  }
  if (c < x + size && x <= c && r < y + size && y <= r) {
    go(x, y, size / 2);
    go(x + size / 2, y, size / 2);
    go(x, y + size / 2, size / 2);
    go(x + size / 2, y + size / 2, size / 2);
  } else {
    ret += size * size;
  }
}
int main() {
  cin >> n >> r >> c;
  go(0, 0, pow(2, n));
}