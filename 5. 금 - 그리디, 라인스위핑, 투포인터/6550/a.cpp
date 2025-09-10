#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string s, t;
int curr;

void init() { curr = 0; }

void go() {
  for (int i = 0; i < t.length(); i++) {
    if (s[curr] == t[i]) curr++;
  }
  if (curr == s.length())
    cout << "Yes\n";
  else
    cout << "No\n";
}

int main() {
  fastIO;
  while (cin >> s >> t) {
    init();
    go();
  };
  return 0;
}