#include <bits/stdc++.h>
using namespace std;
int a[100004];
int n, k, ret, front, rear, max_nb;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < k; i++) ret += a[i];
  max_nb = ret;
  front = 0, rear = k - 1;
  for (int i = 0; i < n - k; i++) {
    ret = ret + a[++rear] - a[front++];
    max_nb = max(max_nb, ret);
  }
  cout << max_nb << "\n";
  return 0;
}