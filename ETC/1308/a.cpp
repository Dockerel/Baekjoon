#include <bits/stdc++.h>
using namespace std;
int ay, am, ad, by, bm, bd;
int isLeap(int y) {
  if (y % 4 == 0) {
    if (y % 400 == 0)
      return 1;
    else if (y % 100 == 0)
      return 0;
    else
      return 1;
  }
  return 0;
}
int month(int y, int m) {
  if (m == 2) {
    if (isLeap(y))
      return 29;
    else
      return 28;
  } else if (m == 4 || m == 6 || m == 9 || m == 10 || m == 12)
    return 31;
  else
    return 30;
}
int from1(int y, int m, int d) {
  int date = 0;
  for (int i = 1; i <= y - 1; i++) {
    if (isLeap(i)) {
      date += 366;
    } else
      date += 365;
  }
  for (int i = 1; i <= m - 1; i++) {
    date += month(y, i);
  }
  date += d;
  return date;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> ay >> am >> ad;
  cin >> by >> bm >> bd;
  cout << from1(ay, am, ad) << "\n";
  cout << from1(by, bm, bd) << "\n";
  cout << from1(by, bm, bd) - from1(ay, am, ad) << "\n";
}