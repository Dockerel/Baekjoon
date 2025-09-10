#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using namespace std;

int n, a[100004];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  return;
}

int divideConquer(int start, int end) {
  if (start == end) return a[start];
  int mid = (start + end) / 2;
  int left, right, sum;
  left = right = -2147483640;
  sum = 0;
  for (int i = mid; i >= start; i--) {
    sum += a[i];
    left = max(left, sum);
  }
  sum = 0;
  for (int i = mid + 1; i <= end; i++) {
    sum += a[i];
    right = max(right, sum);
  }
  int subArr = max(divideConquer(start, mid), divideConquer(mid + 1, end));
  return max(left + right, subArr);
}

int main() {
  fastIO;
  init();
  cout << divideConquer(0, n - 1) << "\n";
  return 0;
}