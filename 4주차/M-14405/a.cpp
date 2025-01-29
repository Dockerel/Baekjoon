#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string s;
int ret;  // 0: NO, 1: YES

void init() {
  cin >> s;
  ret = 1;
}

void go() {
  for (int i = 0; i < s.size();) {
    if (s[i] == 'p') {
      if (i + 1 >= s.size() || s[i + 1] != 'i') {
        ret = 0;
        break;
      }
      i += 2;
    } else if (s[i] == 'k') {
      if (i + 1 >= s.size() || s[i + 1] != 'a') {
        ret = 0;
        break;
      }
      i += 2;
    } else if (s[i] == 'c') {
      if (i + 1 >= s.size() || s[i + 1] != 'h' || i + 2 >= s.size() ||
          s[i + 2] != 'u') {
        ret = 0;
        break;
      }
      i += 3;
    } else {
      ret = 0;
      break;
    }
  }
  cout << (ret ? "YES" : "NO") << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}