#include <bits/stdc++.h>
using namespace std;
int a[9];
int n = 0;
void Print(int n1, int n2) {
  for (int i = 0; i < 9; i++) {
    if (i != n1 && i != n2) cout << a[i] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    cin >> a[i];
    n += a[i];
  }
  n -= 100;

  sort(a, a + 9);

  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (a[i] + a[j] == n) {
        Print(i, j);
        exit(0);
      }
      if (a[i] + a[j] > n) break;
    }
  }

  return 0;
}