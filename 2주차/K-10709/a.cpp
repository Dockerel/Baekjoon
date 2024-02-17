#include <bits/stdc++.h>
using namespace std;
int h, w, c;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s;
    c = -1;
    for (int j = 0; j < w; j++) {
      if (s[j] == 'c') {
        c = j;
      }
      if (c == -1)
        cout << -1 << " ";
      else
        cout << j - c << " ";
    }
    cout << "\n";
  }

  return 0;
}