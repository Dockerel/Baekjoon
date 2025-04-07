#include <bits/stdc++.h>
using namespace std;

int n;
int a[68][68];
char s[68];

string zip(int y, int x, int nb) {
  string s1, s2, s3, s4;
  if (nb % 2 == 0) {
    s1 = zip(y, x, nb / 2);
    s2 = zip(y, x + nb / 2, nb / 2);
    s3 = zip(y + nb / 2, x, nb / 2);
    s4 = zip(y + nb / 2, x + nb / 2, nb / 2);
    if (s1 == s2 && s2 == s3 && s3 == s4 && s1.length() == 1) {
      return s1;
    } else {
      return "(" + s1 + s2 + s3 + s4 + ")";
    }
  } else {
    return to_string(a[y][x]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  cout << zip(0, 0, n) << "\n";

  return 0;
}