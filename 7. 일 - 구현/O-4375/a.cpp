#include <bits/stdc++.h>
using namespace std;
int n, tmp;
int main() {
  while (cin >> n) {
    tmp = 1 % n;
    for (int i = 1;; i++) {
      if (tmp == 0) {
        cout << i << "\n";
        break;
      }
      tmp = ((tmp * 10) + 1) % n;
    }
  }
  return 0;
}