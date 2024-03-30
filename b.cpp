#include <bits/stdc++.h>
using namespace std;

int t, r;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> r >> s;
    for (int j = 0; j < s.length(); j++) {
      for (int k = 0; k < r; k++) {
        cout << s[j];
      }
    }
    cout << "\n";
  }

  return 0;
}