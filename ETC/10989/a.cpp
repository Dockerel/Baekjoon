#include <bits/stdc++.h>

using namespace std;

int a[8] = {2, 8, 7, 1, 3, 5, 6, 4};

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

void QUICKSORT(int p, int r) {
  if (p < r) {
    int q = PATITION(p, r);
    QUICKSORT(p, q - 1);
    QUICKSORT(q + 1, r);
  }
}

int main() {
  QUICKSORT(0, 7);

  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";

  return 0;
}