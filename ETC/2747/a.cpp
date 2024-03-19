#include <iostream>
using namespace std;
int n, a[50];
int main() {
  cin >> n;
  a[0] = 0;
  a[1] = 1;
  if (n <= 1) {
    cout << a[n] << "\n";
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  cout << a[n] << "\n";
  return 0;
}