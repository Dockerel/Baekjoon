#include <bits/stdc++.h>
using namespace std;

int n;
string s;
stack<char> st;

void vps(string s) {
  while (!st.empty()) st.pop();
  for (int i = 0; i < s.length(); i++) {
    if (st.empty() || s[i] == '(') {
      st.push(s[i]);
    } else {
      if (st.top() == '(')
        st.pop();
      else
        st.push(s[i]);
    }
  }
  if (st.empty())
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vps(s);
  }

  return 0;
}