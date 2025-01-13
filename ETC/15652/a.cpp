#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
vector<int> st;

void init() { cin >> n >> m; }

void myFor(int start) {
  for (int i = start; i <= n; i++) {
    st.push_back(i);
    if (st.size() == m) {
      for (auto it : st) {
        cout << it << " ";
      }
      cout << "\n";
    } else {
      myFor(i);
    }
    st.pop_back();
  }
}

void go() { myFor(1); }

int main() {
  fastIO;
  init();
  go();
  return 0;
}