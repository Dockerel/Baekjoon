#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, a[24], num;
string s;
void init() {
  cin >> n;
  memset(a, 0, sizeof(a));
  return;
}
int cmdParse(string cmd) {
  if (!cmd.compare("add"))
    return 0;
  else if (!cmd.compare("remove"))
    return 1;
  else if (!cmd.compare("check"))
    return 2;
  else if (!cmd.compare("toggle"))
    return 3;
  else if (!cmd.compare("all"))
    return 4;
  else if (!cmd.compare("empty"))
    return 5;
}
void go() {
  while (n--) {
    cin >> s;
    switch (cmdParse(s)) {
      case 0:
        cin >> num;
        if (a[num] == 0) a[num] = 1;
        break;
      case 1:
        cin >> num;
        if (a[num] == 1) a[num] = 0;
        break;
      case 2:
        cin >> num;
        if (a[num] == 1)
          cout << "1\n";
        else
          cout << "0\n";
        break;
      case 3:
        cin >> num;
        if (a[num] == 0)
          a[num] = 1;
        else
          a[num] = 0;
        break;
      case 4:
        for (int i = 1; i <= 20; i++)
          if (a[i] == 0) a[i] = 1;
        break;
      case 5:
        for (int i = 1; i <= 20; i++)
          if (a[i] == 1) a[i] = 0;
        break;
    }
  }
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}