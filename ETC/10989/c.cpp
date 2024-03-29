#include <bits/stdc++.h>

using namespace std;

int n, a[1000004];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  return;
}

int PATITION(int p, int r) {
  int x = a[r];  // pivot
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (a[j] < x) {
      i += 1;
      swap(a[i], a[j]);
    }
  }
  swap(a[i + 1], a[r]);  // pivot 위치 지정
  return i + 1;          // pivot 위치 리턴
}

int RANDOMIZED_PATITION(int p, int r) {
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> dist(p, r);
  int i = dist(mt);
  swap(a[i], a[r]);
  return PATITION(p, r);
}

void QUICKSORT(int p, int r) {
  if (p < r) {
    int q = RANDOMIZED_PATITION(p, r);
    QUICKSORT(p, q - 1);  // pivot
    QUICKSORT(q + 1, r);  // 빼고 지정
  }
}

int main() {
  init();

  QUICKSORT(0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << a[i] << "\n";
  }

  return 0;
}