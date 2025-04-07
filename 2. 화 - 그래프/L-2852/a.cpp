#include <bits/stdc++.h>
#define prev hi
using namespace std;
int n, o, A, B, asum, bsum;
string s, prev;

void print(int sum) {
  int tmp1 = sum / 60;
  int tmp2 = sum % 60;

  if (tmp1 < 10) cout << 0;
  cout << tmp1 << ":";
  if (tmp2 < 10) cout << 0;
  cout << tmp2 << "\n";
}

int changeToInt(string a) {
  return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 5).c_str());
}

void go(int &sum, string s) { sum += (changeToInt(s) - changeToInt(prev)); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  A = B = 0;
  asum = bsum = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> o >> s;
    if (A > B)
      go(asum, s);
    else if (A < B)
      go(bsum, s);
    prev = s;
    o == 1 ? A++ : B++;
  }
  if (A > B)
    go(asum, "48:00");
  else if (A < B)
    go(bsum, "48:00");
  prev = s;

  print(asum);
  print(bsum);
}