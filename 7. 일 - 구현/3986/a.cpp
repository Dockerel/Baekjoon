#include <bits/stdc++.h>
using namespace std;
int n, ret = 0;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int j = 0; j < n; j++) {
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (st.empty() || st.top() != s[i])
        st.push(s[i]);
      else
        st.pop();
    }
    if (st.empty()) ret++;
  }
  cout << ret << "\n";
  return 0;
}