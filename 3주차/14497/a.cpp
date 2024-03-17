#include <bits/stdc++.h>
using namespace std;
int n, m, x1, y1, x2, y2;
char a[304][304];
int v[304][304];
string s;
void fastIO() {
  ios_base::sync_with_stdio;
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fastIO();
  cin >> n >> m;
  cin >> x1 >> y1 >> x2 >> y2;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];
    }
  }
  //   go(x1, y1);
}