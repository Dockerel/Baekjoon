#include <bits/stdc++.h>
#define fastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
using namespace std;
int r, c;
char a[24][24];
char alpha[30];
void init() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> a[i][j];
    }
  }
  memset(v, 0, sizeof(v));
  memset(alpha, 0, sizeof(alpha));
}
void solve() {
  queue<pair<int, int>> q;
  alpha[a[0][0] - 'A'] = 1;
  q.push({0, 0});
  while () }
int main() {
  fastIO;
  init();
  solve();
}