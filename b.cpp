#include <bits/stdc++.h>

using namespace std;

int n, ss;
long long ret;
int a[10004];
vector<int> cs;

int main() {
  ret = ss = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ss += a[i];
  }
  cs.push_back(0);
  for (int i = 1; i <= 2 * n; i++) {
    cs.push_back(cs[i - 1] + a[(i - 1) % n]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j < i + n; j++) {
      int temp = cs[j + 1] - cs[i];
      if (temp < 0) {
        ret += ceil(double(abs(temp)) / ss);
      }
    }
  }

  printf("%d\n", ret);
  return 0;
}