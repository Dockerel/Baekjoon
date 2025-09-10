#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, s, num, _prev, _sum;
int a[100004];

int st, ed, ret;

void init() {
  cin >> n >> s;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> num;

    if (s <= num) {
      cout << "1\n";
      exit(0);
    }

    a[i] = _prev + num;
    _prev = a[i];
  }

  ret = 0;
  st = 0, ed = 2;
}

void go() {
  while (true) {
    if (ed - st < 2) break;
    if (ed > n) break;

    _sum = a[ed] - a[st];
    if (s <= _sum) {
      ret = (ret == 0 ? ed - st : min(ret, ed - st));
      st++;
    } else {
      ed++;
    }
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}