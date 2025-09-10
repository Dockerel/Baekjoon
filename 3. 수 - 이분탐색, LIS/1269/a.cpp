#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int a, b, n, ret;
vector<int> A, B;

void init() {
  cin >> a >> b;
  for (int _ = 0; _ < a; _++) {
    cin >> n;
    A.push_back(n);
  }
  for (int _ = 0; _ < b; _++) {
    cin >> n;
    B.push_back(n);
  }
  ret = 0;
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
}

void go() {
  int idx1, idx2;
  idx1 = idx2 = 0;
  while (idx1 < a && idx2 < b) {
    if (A[idx1] == B[idx2]) {
      idx1 += 1;
      idx2 += 1;
    } else {
      ret += 1;
      if (A[idx1] > B[idx2]) {
        idx2 += 1;
      } else {
        idx1 += 1;
      }
    }
  }

  ret += (a - idx1) + (b - idx2);

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}