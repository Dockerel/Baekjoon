#include <bits/stdc++.h>
using namespace std;
string s;
int ret = 0;
int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    string temp = "";
    if (s[i] == '1') {
      if (i + 1 < s.length() && s[i + 1] == '0') {
        temp += "10";
        i++;
      } else {
        temp += '1';
      }
    } else {
      temp += s[i];
    }
    ret += stoi(temp);
  }
  cout << ret << "\n";
  return 0;
}