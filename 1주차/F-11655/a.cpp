#include <bits/stdc++.h>
using namespace std;
char s[104];
int tmp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin.getline(s, 104, '\n');
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == ' ' || isdigit(s[i]))
      cout << s[i];
    else {
      if (s[i] > 'Z') {
        tmp = s[i] + 13;
        if (tmp > 'z') {
          tmp = 96 + (tmp - 'z');
        }
      } else {
        tmp = s[i] + 13;
        if (tmp > 'Z') {
          tmp = 64 + (tmp - 'Z');
        }
      }
      cout << char(tmp);
    }
  }
  cout << "\n";
  return 0;
}