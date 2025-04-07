#include <bits/stdc++.h>
using namespace std;
int a[29] = {0};
char s[34];
int result = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a[s[0] - 'a'] += 1;
  }

  for (int i = 'a'; i <= 'z'; i++) {
    if (a[i - 'a'] >= 5) {
      result = 1;
      cout << char(i);
    }
  }
  if (result == 1)
    cout << "\n";
  else
    cout << "PREDAJA\n";
  return 0;
}