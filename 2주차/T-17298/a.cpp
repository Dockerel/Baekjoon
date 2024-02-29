#include <bits/stdc++.h>
using namespace std;
int n, a, idx = 1;
stack<pair<int, int>> st;  // {index, a}
int ret[1000004];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    while (1) {
      if (st.empty() || st.top().second >= a) {
        st.push({idx++, a});
        break;
      } else {
        ret[st.top().first] = a;
        st.pop();
      }
    }
  }

  while (!st.empty()) {
    ret[st.top().first] = -1;
    st.pop();
  }

  for (int i = 1; i <= n; i++) cout << ret[i] << " ";
  cout << "\n";

  return 0;
}