#include <bits/stdc++.h>
using namespace std;

vector<string> a1, a2;
int fullSize;

string intToBinary(int n) {
  string binary = "";
  while (n > 1) {
    binary = char((n % 2) + '0') + binary;
    n /= 2;
  }
  binary = char(n + '0') + binary;
  if (binary.length() != fullSize) {
    int tmp = binary.length();
    for (int i = 0; i < fullSize - tmp; i++) {
      binary = '0' + binary;
    }
  }
  return binary;
}

void change(vector<int> arr, vector<string> *a) {
  string binary = "";
  for (int n : arr) {
    binary = intToBinary(n);
    a->push_back(binary);
  }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
  fullSize = n;
  vector<string> answer;

  change(arr1, &a1);
  change(arr2, &a2);

  for (int i = 0; i < n; i++) {
    string s1 = a1.at(i);
    string s2 = a2.at(i);
    string ret = "";
    for (int j = 0; j < n; j++) {
      if (s1[j] == '1' || s2[j] == '1')
        ret += '#';
      else
        ret += ' ';
    }
    answer.push_back(ret);
  }

  return answer;
}