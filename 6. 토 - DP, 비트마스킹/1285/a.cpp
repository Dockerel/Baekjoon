#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
int a[24];
string s;

int ret = 404;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    replace(s.begin(), s.end(), 'H', '1');
    replace(s.begin(), s.end(), 'T', '0');
    a[i] = stoi(s, nullptr, 2);
  }
}

void flip(int idx) { a[idx] = ~a[idx]; }

void go(int num) {
  if (num == n) {
    // col 확인
    int _sum = 0;
    for (int i = 0; i < n; i++) {
      int temp = 0;
      for (int j = 0; j < n; j++) {
        if (a[j] & (1 << i)) temp++;
      }
      _sum += min(temp, n - temp);
    }
    ret = min(ret, _sum);
    return;
  }

  go(num + 1);  // num에서 flip 안한 상태
  flip(num);

  go(num + 1);  // num에서 flip한 상태
  flip(num);
}

int main() {
  fastIO;
  init();
  go(0);
  cout << ret << "\n";
  return 0;
}