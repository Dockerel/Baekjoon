#include <bits/stdc++.h>
using namespace std;
int n1, n2, n3;
char p[104];
char s[104];

int cmp() {
  for (int i = 0; i < n2; i++) {
    if (p[i] != s[i]) return 0;
  }
  for (int i = 1; i < strlen(p) - n2; i++) {
    if (p[strlen(p) - i] != s[strlen(s) - i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n1;
  cin >> p;
  for (int i = 0; i < strlen(p); i++)
    if (p[i] == '*') {
      n2 = i;
      break;
    }

  for (int i = 0; i < n1; i++) {
    cin >> s;
    if (strlen(p) - 1 > strlen(s) || !cmp())
      cout << "NE\n";
    else
      cout << "DA\n";
  }
  return 0;
}