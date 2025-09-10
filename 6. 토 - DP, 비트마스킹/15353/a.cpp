#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string s1, s2;
vector<int> num1;
vector<int> num2;
vector<int> ret;

void init() {
  cin >> s1 >> s2;
  for (int i = s1.length() - 1; i >= 0; i--) {
    num1.push_back(s1[i] - '0');
  }
  if (s1.length() < s2.length()) {
    for (int i = 0; i < s2.length() - s1.length(); i++) {
      num1.push_back(0);
    }
  }
  for (int i = s2.length() - 1; i >= 0; i--) {
    num2.push_back(s2[i] - '0');
  }
  if (s2.length() < s1.length()) {
    for (int i = 0; i < s1.length() - s2.length(); i++) {
      num2.push_back(0);
    }
  }
}

void go() {
  int carry = 0;
  for (int i = 0; i < num1.size(); i++) {
    int temp = num1[i] + num2[i] + carry;
    if (temp >= 10) {
      carry = (temp / 10);
    } else {
      carry = 0;
    }
    ret.push_back(temp % 10);
  }
  if (carry > 0) ret.push_back(carry % 10);
  if (carry / 10 > 0) ret.push_back(carry / 10);

  for (int i = ret.size() - 1; i >= 0; i--) {
    cout << ret[i] << "";
  }
  cout << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}