#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string zero(string s) {
  string tmp = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '0') {
      for (int j = i; j < s.length(); j++) {
        tmp += s[j];
      }
      break;
    }
  }
  if (!tmp.compare(""))
    return "0";
  return tmp;
}

void calc(string s) {
  string tmp = "";
  for (int i = 0; i < s.length(); i++) {
    if (!isdigit(s[i])) {
      if (tmp.compare("")) {
        v.push_back(zero(tmp));
        tmp = "";
      }
      continue;
    } else {
      tmp += s[i];
    }
  }
  if (tmp.compare(""))
    v.push_back(zero(tmp));
}

bool cmp(string a, string b) {
  if (a.length() == b.length()) {
    for (int i = 0; i < a.length(); i++) {
      if (a[i] != b[i]) {
        return a[i] < b[i];
      }
    }
  }
  return a.length() < b.length();
}

int main() {
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    calc(s);
  }
  sort(v.begin(), v.end(), cmp);
  for (auto it : v) {
    cout << it << "\n";
  }
  return 0;
}