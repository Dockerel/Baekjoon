#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int temp = i;
    int num = i;

    while (temp > 0) {
      num += temp % 10;
      temp /= 10;
    }

    if (num == n) {
      cout << i << "\n";
      n = 0;
      break;
    }
  }
  if (n != 0) cout << "0\n";
}