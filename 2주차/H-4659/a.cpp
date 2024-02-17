#include <bits/stdc++.h>
using namespace std;
char s[24];
int charType(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
  return 0;
}
void check(char* s1) {
  int aeiou = 0;
  int doub = 1;
  int triple = 1;

  for (int i = 0; i < strlen(s1); i++) {
    if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' ||
        s1[i] == 'u')
      aeiou = 1;

    if (i > 0) {
      if (s[i] == s[i - 1]) {
        if (!(s[i] == 'e' || s[i] == 'o')) {
          doub = 0;
          break;
        }
      }

      if (i > 1) {
        if (charType(s[i]) == charType(s[i - 1]) &&
            charType(s[i]) == charType(s[i - 2])) {
          triple = 0;
          break;
        }
      }
    }
  }
  cout << "<" << s1 << ">";
  if (aeiou && doub && triple)
    cout << " is acceptable.\n";
  else
    cout << " is not acceptable.\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //   1. 모음 aeiou 중 하나를 반드시 포함
  //   2. 모음이 3개 혹은 자음이 3개 연속으로 오면 x
  //   3. 같은 글자가 연속적으로 2번 오면 안되는데 ee와 oo는 허용
  while (1) {
    cin >> s;
    if (!strcmp(s, "end")) break;
    check(s);
  }
  return 0;
}