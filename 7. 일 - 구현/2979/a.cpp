#include <bits/stdc++.h>
using namespace std;
int fare[3];
int a[104], b[104], c[104];
int start, finish, ret = 0, n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> fare[0] >> fare[1] >> fare[2];
  for (int i = 0; i < 3; i++) {
    cin >> start >> finish;
    if (i == 0)
      for (int j = start + 1; j <= finish; j++) a[j] = 1;
    if (i == 1)
      for (int j = start + 1; j <= finish; j++) b[j] = 1;
    if (i == 2)
      for (int j = start + 1; j <= finish; j++) c[j] = 1;
  }
  for (int i = 0; i <= 100; i++) {
    n = 0;
    if (a[i] == 1) n++;
    if (b[i] == 1) n++;
    if (c[i] == 1) n++;
    if (n > 0) ret += (fare[n - 1] * n);
  }
  cout << ret << "\n";
  return 0;
}
