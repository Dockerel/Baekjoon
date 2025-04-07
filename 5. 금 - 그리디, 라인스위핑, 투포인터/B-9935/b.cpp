#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string s, ret, bomb;

void init() {
  cin >> s;
  cin >> bomb;
  ret = "";
}

void go() {
  for (char c : s) {
    ret += c;
    if (ret.size() >= bomb.size() &&
        ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb) {
      ret.erase(ret.end() - bomb.size(), ret.end());
    }
  }
  if (!ret.size()) {
    cout << "FRULA\n";
    return;
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}