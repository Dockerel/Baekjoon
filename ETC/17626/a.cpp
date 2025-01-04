#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, ret;

void init() {
  cin >> n;
  ret = 4;
}

int isSquare(int num) {
  int temp = sqrt(num);
  return 1 ? num == temp * temp : 0;
}

void go() {
  if (isSquare(n)) {
    ret = 1;
    return;
  }

  for (int i = sqrt(n); i > 0; i--) {
    if (isSquare(n - i * i)) {
      ret = 2;
      return;
    }
  }

  for (int i = sqrt(n); i > 0; i--) {
    for (int j = sqrt(n - i * i); j > 0; j--) {
      if (isSquare(n - i * i - j * j)) {
        ret = 3;
        return;
      }
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  cout << ret << "\n";
  return 0;
}