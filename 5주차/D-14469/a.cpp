#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n;
int start, delay;
int ret;

vector<pii> v;

void init() {
  cin >> n;
  for (int _ = 0; _ < n; _++) {
    cin >> start >> delay;
    v.push_back({start, delay});
  }
  sort(v.begin(), v.end());
  ret = 0;
}

void go() {
  for (auto it : v) {
    if (ret < it.ff) {
      ret = it.ff + it.ss;
    } else {
      ret += it.ss;
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