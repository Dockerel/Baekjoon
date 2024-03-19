#include <iostream>
using namespace std;
long long n, x, y, curr;
int main() {
  cin >> n;
  x = 0;
  y = 1;
  if (n <= 1) {
    cout << n << "\n";
    return 0;
  }
  n %= 1500000;

  for (int i = 2; i <= n; i++) {
    curr = x + y;

    if (curr > 1000000) {
      curr %= 1000000;
    }

    x = y, y = curr;
  }
  cout << curr << "\n";

  return 0;
}