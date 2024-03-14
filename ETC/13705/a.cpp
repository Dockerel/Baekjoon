#include <bits/stdc++.h>
using namespace std;
using LF = __float128;

int a, b, c;

LF powfl(LF x, int n) {
  LF ret = 1;
  for (int i = 0; i < n; i++) {
    ret *= x;
  }
  return x;
}

LF sinfl(LF x) {
  LF ret = 0;
  int j = 1;
  for (int i = 1; i < 50; i += 2) {
    ret += (pow(-1, i) * powfl(x, i) * tgamma(i + 1));
  }
  return ret;
}

int main() {
  cin >> a >> b >> c;

  LF l = (c - b) / a, r = (c + b) / a, x, tmp, ret;
  int t = 100;
  for (int i = 0; i < t; i++) {
    x = (l + r) / 2;
    LF tmp = a * x + b * sinfl(x);
    (tmp < c ? l : r) = x;
  }
  printf(".6lf\n", (double)(l + r) / 2);
}