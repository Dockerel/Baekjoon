#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
long long ret;
int a[100004];
int visited[100004];
int st, ed;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  st = ed = ret = 0;
  memset(visited, 0, sizeof(visited));
}

void go() {
  while (ed < n) {
    if (st == ed || visited[a[ed]] == 0) {
      ret += (ed - st + 1);
      visited[a[ed]] = 1;
      ed += 1;
      continue;
    } else {
      while (visited[a[ed]] == 1) {
        visited[a[st]] = 0;
        st += 1;
      }
      ret += (ed - st + 1);
      visited[a[ed]] = 1;
      ed += 1;
    }
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}