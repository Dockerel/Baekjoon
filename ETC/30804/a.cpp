#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>

using namespace std;

int n, ret;
int a[200004];
vector<pii> fruits;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int temp = 0;
    int prev = a[i];
    while (i < n && prev == a[i]) {
      i++;
      temp++;
    }
    i--;
    fruits.push_back({a[i], temp});
  }
  n = fruits.size();
  ret = -1;
}

void go() {
  bool flag = false;
  ;
  int left, right, kind;
  left = right = kind = 0;

  int *type = new int[10]{0};

  // 슬라이딩 윈도우
  while (1) {
    // kind 2개 될때까지 right++
    while (1) {
      pii it = fruits[right];
      if (type[it.first] == 0) kind++;
      if (kind > 2) break;
      type[it.first] += it.second;
      right++;
      if (right == n) {
        flag = true;
        break;
      }
    }
    kind--;

    // ret 갱신
    int temp_sum = 0;
    for (int i = 1; i <= 9; i++) temp_sum += type[i];
    ret = max(ret, temp_sum);

    if (flag) break;
    // kind 1개 될때까지 left++
    while (kind > 1) {
      pii it = fruits[left];
      if (type[it.first] - it.second == 0) kind--;
      type[it.first] -= it.second;
      left++;
    }
  }
  delete[] type;
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}