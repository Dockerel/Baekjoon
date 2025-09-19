#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, n, k;
int nums[1004], sorted_nums[1004];

void init() { cin >> t; }

void go() {
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    sorted_nums[i] = nums[i];
  }

  sort(sorted_nums, sorted_nums + n);

  int curr = 0;
  for (int i = 0; i < n; i++) {
    if (sorted_nums[curr] == nums[i]) {
      curr += 1;
      if (curr == n) break;
    }
  }

  cout << k << " " << n - curr << "\n";
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < t; _++) {
    go();
  }
  return 0;
}