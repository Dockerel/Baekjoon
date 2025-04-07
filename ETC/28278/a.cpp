#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, cmd;
string s;
stack<string> st;

void init() { cin >> n; }

void go() {
  for (int _ = 0; _ < n; _++) {
    cin >> cmd;
    switch (cmd) {
      case 1:
        cin >> s;
        st.push(s);
        break;
      case 2:
        if (!st.empty()) {
          cout << st.top() << "\n";
          st.pop();
        } else {
          cout << "-1\n";
        }
        break;
      case 3:
        cout << st.size() << "\n";
        break;
      case 4:
        cout << (st.empty() ? 1 : 0) << "\n";
        break;
      case 5:
        cout << (!st.empty() ? st.top() : "-1") << "\n";
        break;
      default:
        break;
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}