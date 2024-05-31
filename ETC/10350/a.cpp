#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, ret, _sum;
int a[10004];
vector<int> c_sum;

void init() {
  ret = _sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    _sum += a[i];
  }
}

void go() {
  c_sum.push_back(0);
  for (int i = 1; i < 2 * n; i++) {
    c_sum.push_back(c_sum[i - 1] + a[(i - 1) % n]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < i + n; j++) {  // i:0, j:1~3
      int temp = c_sum[j] - c_sum[i];
      if (temp < 0) {
        ret += ceil(double(abs(temp)) / _sum);
      }
    }
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}