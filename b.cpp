#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m;
int a[20000010];
string s;
string del;
void init() {
  cin >> n;
  cin >> m;
  cin >> s;
  del = "I";
  for (int i = 0; i < n; i++) del += "OI";
  a[0] = -1;
  a[1] = -1;
  a[2] = 0;
  for (int i = 3; i < 2 * n + 1; i++) {
    a[i] = a[i - 2] + 2;
  }
  return;
}
void go() {
  for (int i = 0; i < s.length(); i++) {
    }
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}