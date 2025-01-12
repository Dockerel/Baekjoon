#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string s1, s2, s3;
int idx, num;

void init() {
  cin >> s1;
  cin >> s2;
  cin >> s3;
}

bool isInt(string s, int n) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] < '0' || s[i] > '9') {
      return false;
    }
  }
  num = stoi(s);
  idx = n;
  return true;
}

void fizzbuzz(int n) {
  if (n % 15 == 0) {
    cout << "FizzBuzz\n";
  } else if (n % 3 == 0) {
    cout << "Fizz\n";
  } else if (n % 5 == 0) {
    cout << "Buzz\n";
  } else {
    cout << n << "\n";
  }
}

void go() {
  if (isInt(s1, 1) || isInt(s2, 2) || isInt(s3, 3)) {
    while (true) {
      if (idx == 3) {
        fizzbuzz(num + 1);
        return;
      } else {
        idx++;
        num++;
      }
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}