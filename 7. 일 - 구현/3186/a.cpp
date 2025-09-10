#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int k, l, n;
string s;
int curr;
vector<int> ret;

void init() {
  cin >> k >> l >> n;
  cin >> s;
  curr = 0;
}

int strcomp(int stat, int loc) {
  int size = (stat == 0 ? l : k);
  if (loc + size - 1 >= n) {
    return 0;
  }
  for (int i = loc; i < loc + size; i++) {
    if (s[i] - '0' != stat) {
      return 0;
    }
  }
  return 1;
}

void go() {
  for (int i = 0; i < n; i++) {
    switch (s[i] - '0') {
      case 0:
        if (curr == 1) {
          if (strcomp(0, i)) {
            ret.push_back(i + l);
            i += l - 1;
            curr = 0;
          }
        }
        break;
      case 1:
        if (curr == 0) {
          if (strcomp(1, i)) {
            curr = 1;
            i += k - 1;
          }
        }
        break;
      default:
        break;
    }
  }
  if (curr == 1) {
    ret.push_back(n + l);
  }
  if (ret.size()) {
    for (auto it : ret) {
      cout << it << "\n";
    }
  } else {
    cout << "NIKAD\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}