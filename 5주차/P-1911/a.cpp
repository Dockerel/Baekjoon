#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, l;
int st, ed;

vector<pair<int, int>> v;

int curr, ret;

void init() {
  cin >> n >> l;
  for (int _ = 0; _ < n; _++) {
    cin >> st >> ed;
    v.push_back({st, ed});
  }
  sort(v.begin(), v.end());
  curr = v[0].ff;
}

void go() {
  for (int i = 0; i < v.size(); i++) {
    auto it = v[i];

    while (curr < it.ss) {
      curr += l;
      ret += 1;
    }

    while (1) {
      if (i + 1 == v.size()) break;

      auto nxt = v[i + 1];
      if (curr < nxt.ff) {
        curr = nxt.ff;
        break;
      } else if (nxt.ss < curr) {
        i += 1;
        continue;
      } else {
        break;
      }
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