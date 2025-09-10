#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

string s, bomb;
stack<char> st;

void init() {
  cin >> s;
  cin >> bomb;
}

void go() {
  for (char c : s) {
    st.push(c);
    if (st.size() >= bomb.size() && st.top() == bomb[bomb.size() - 1]) {
      string temp = "";
      for (int _ = 0; _ < bomb.size(); _++) {
        temp += st.top();
        st.pop();
      }
      reverse(temp.begin(), temp.end());
      if (bomb != temp) {
        for (auto it : temp) {
          st.push(it);
        }
      }
    }
  }
  if (!st.size()) {
    cout << "FRULA\n";
    return;
  }
  string ret = "";
  while (!st.empty()) {
    ret += st.top();
    st.pop();
  }
  reverse(ret.begin(), ret.end());
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}