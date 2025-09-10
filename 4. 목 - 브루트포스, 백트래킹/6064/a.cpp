#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, m, n, x, y;
int x_p, y_p, ret;

void init() { cin >> t; }

int gcd(int a, int b)  // a > b
{
  int r;
  while (1) {
    int r = a % b;

    if (r == 0) return b;
    a = b;
    b = r;
  }
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

void go() {
  x_p = x;
  y_p = (x % n == 0 ? n : x % n);
  ret = x;

  int _lcm = lcm(max(m, n), min(m, n));

  while (true) {
    if (x_p == x && y_p == y) {
      cout << ret << "\n";
      return;
    }

    if (ret > _lcm) {
      cout << "-1\n";
      return;
    }

    y_p = (((y_p + m) % n) == 0 ? n : ((y_p + m) % n));
    ret += m;
  }
}

int main() {
  fastIO;
  init();
  for (int i = 0; i < t; i++) {
    cin >> m >> n >> x >> y;
    go();
  }
  return 0;
}