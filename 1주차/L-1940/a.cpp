#include <bits/stdc++.h>
using namespace std;
int n, m, ret = 0;
int a[15004];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  cin >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] + a[j] == m) {
        ret++;
        break;
      }
    }
  }
  cout << ret << "\n";
  return 0;
}