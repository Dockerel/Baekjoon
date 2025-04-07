#include <bits/stdc++.h>
using namespace std;
char s[104];
int n;
int a[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s;
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a'] += 1;
  }
  for (int i = 0; i < 26; i++) {
    cout << a[i] << " ";
  }
  return 0;
}