#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
string s;
int curr, cnt, ret;

void init() {
  cin >> n;
  cin >> m;
  cin >> s;
}

void go() {
  while (curr < m - 2) {
    if (s[curr] == 'I' && s[curr + 1] == 'O' && s[curr + 2] == 'I') {
      curr += 2;
      cnt += 1;
      if (cnt == n) {
        ret += 1;
        cnt -= 1;
      }
    } else {
      curr += 1;
      cnt = 0;
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  cout << ret << "\n";
  return 0;
}