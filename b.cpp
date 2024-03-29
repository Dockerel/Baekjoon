#include <bits/stdc++.h>

using namespace std;

int n;
int a[8] = {3, 4, 2, 7, 6, 8, 5, 1};

int PATITION(int p, int r) {
  int x = a[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (a[j] < x) {
      i += 1;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[r]);
  return i + 1;
}

int RANDOMIZED_PATITION(int p, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(p, r);
  int i = dist(mt);
  swap(a[i], a[r]);
  return PATITION(p, r);
}

int SELECT(int p, int r, int k) {
  if (p == r) return a[p];

  int q = RANDOMIZED_PATITION(p, r);
  int i = q - p + 1;
  if (k == i) {
    return a[q];
  } else if (k < i) {
    return SELECT(p, q - 1, k);
  } else {
    return SELECT(q + 1, r, k - i);
  }
}

int main() {
  int target = 4;
  cout << SELECT(0, 7, target) << "\n";

  return 0;
}