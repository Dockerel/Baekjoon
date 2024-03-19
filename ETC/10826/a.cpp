#include <algorithm>
#include <iostream>
using namespace std;
int n;
string x, y, curr;
string stringAdd(string s1, string s2) {
  int num, carry = 0;
  string ret = "";

  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  while (s1.length() < s2.length()) s1 += "0";
  while (s1.length() > s2.length()) s2 += "0";

  for (int i = 0; i < s1.length(); i++) {
    num = (s1[i] - '0' + s2[i] - '0' + carry) % 10;
    ret += to_string(num);
    carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
  }

  if (carry > 0) ret += to_string(carry);

  reverse(ret.begin(), ret.end());

  return ret;
}
int main() {
  cin >> n;
  if (n <= 1) {
    cout << n << "\n";
    return 0;
  }

  x = "0";
  y = "1";
  for (int i = 2; i <= n; i++) {
    curr = stringAdd(x, y);
    x = y, y = curr;
  }
  cout << curr << "\n";

  return 0;
}