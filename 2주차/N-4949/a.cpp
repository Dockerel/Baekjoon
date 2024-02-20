#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;

char op(char c) {
  if (c == '(' || c == ')') return c == '(' ? ')' : '(';
  if (c == '[' || c == ']') return c == '[' ? ']' : '[';
}

char rev_op(char c) {
  if (c == '(' || c == ')') return c == '(' ? ']' : '[';
  if (c == '[' || c == ']') return c == '[' ? ')' : '(';
}

char c1[2] = {'(', ')'};
char c2[2] = {'[', ']'};

void balance(string s) {
  while (!st.empty()) st.pop();
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c1[0] || s[i] == c2[0]) {
      st.push(s[i]);
    } else if (s[i] == c1[1] || s[i] == c2[1]) {
      if (st.empty() || st.top() == rev_op(s[i])) {
        cout << "no\n";
        return;
      } else if (st.top() == op(s[i]))
        st.pop();
    }
  }

  if (st.empty())
    cout << "yes\n";
  else
    cout << "no\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (1) {
    getline(cin, s);
    if (!s.compare(".")) exit(0);
    balance(s);
  }

  return 0;
}
