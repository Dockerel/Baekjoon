#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 1000004

using namespace std;

int n, _size;
int arr[MAX];

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  _size = n;
  return;
}

void SWAP(int idx1, int idx2) {
  int temp;
  temp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = temp;
  return;
}

void MAX_HEAPIFY(int idx) {
  int left, right, _max;
  left = idx * 2;
  right = idx * 2 + 1;
  _max = idx;

  if (left <= _size && arr[left] > arr[_max]) {
    _max = left;
  }
  if (right <= _size && arr[right] > arr[_max]) {
    _max = right;
  }

  if (_max != idx) {
    SWAP(idx, _max);
    MAX_HEAPIFY(_max);
  }

  return;
}

void BUILD_MAX_HEAP() {
  for (int i = _size / 2; i > 0; i--) {
    MAX_HEAPIFY(i);
  }
}

void HEAPSORT() {
  BUILD_MAX_HEAP();
  while (_size > 0) {
    SWAP(1, _size--);
    MAX_HEAPIFY(1);
  }
}

void go() {
  HEAPSORT();

  for (int i = 1; i <= n; i++) {
    cout << arr[i] << "\n";
  }

  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}
