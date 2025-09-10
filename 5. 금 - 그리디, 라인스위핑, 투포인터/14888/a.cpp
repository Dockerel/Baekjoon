#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, a;
vector<int> nums, funcs;

int ret_max, ret_min;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    nums.push_back(a);
  }
  for (int i = 0; i < 4; i++) {
    cin >> a;
    funcs.push_back(a);
  }
  ret_max = -1000000001;
  ret_min = 1000000001;
}

void go(int idx, int result) {
  if (idx == n - 1) {
    ret_max = max(ret_max, result);
    ret_min = min(ret_min, result);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (funcs[i] == 0) continue;

    funcs[i] -= 1;
    int temp_result = result;
    if (i == 0)
      temp_result += nums[idx + 1];
    else if (i == 1)
      temp_result -= nums[idx + 1];
    else if (i == 2)
      temp_result *= nums[idx + 1];
    else
      temp_result /= nums[idx + 1];
    go(idx + 1, temp_result);
    funcs[i] += 1;
  }
}

int main() {
  fastIO;
  init();
  go(0, nums[0]);
  cout << ret_max << "\n";
  cout << ret_min << "\n";
  return 0;
}