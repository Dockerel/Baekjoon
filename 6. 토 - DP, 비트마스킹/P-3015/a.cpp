#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ff first
#define ss second

using namespace std;

int n, h;
long long ret;

stack<pair<int, int>> st;

void init() {
  cin >> n;
  ret = 0;
}

void go() {
  for (int i = 0; i < n; i++) {
    cin >> h;
    int cnt = 1;
    if (st.empty()) {
      st.push({cnt, h});
      continue;
    }

    while (!st.empty()) {
      auto top = st.top();
      if (top.ss <= h) {
        ret += top.ff;
        if (top.ss == h) cnt += top.ff;
        st.pop();
      } else {
        break;
      }
    }
    if (!st.empty()) ret += 1;
    st.push({cnt, h});
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}

// 0 1 2 3 4 5 6
// 2 4 1 2 2 5 1

// 2
// 1
// 2
// 4
// 1