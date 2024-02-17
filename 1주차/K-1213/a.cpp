#include <bits/stdc++.h>
using namespace std;
char s[54];
int a[26];
string front = "", mid = "", rear = "";
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  for (int i = 0; i < strlen(s); i++) a[s[i] - 'A'] += 1;

  for (int i = 0; i < 26; i++) {
    if (a[i] > 0) {
      if (a[i] % 2 == 0) {
        for (int j = 0; j < a[i] / 2; j++) {
          front += char(i + 'A');
          rear = char(i + 'A') + rear;
        }
      } else {
        if (!mid.compare("")) {
          mid += char(i + 'A');
          for (int j = 0; j < ((a[i] - 1) / 2); j++) {
            front += char(i + 'A');
            rear = char(i + 'A') + rear;
          }
        } else {
          cout << "I'm Sorry Hansoo\n";
          exit(0);
        }
      }
    }
  }
  cout << front << mid << rear << "\n";

  return 0;
}