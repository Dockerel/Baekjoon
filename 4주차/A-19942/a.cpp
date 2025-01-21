#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tiiii tuple<int, int, int, int>
#define pit pair<int, tiiii>
#define INF 987654321

using namespace std;

int n;
int _max[4];
vector<pit> foods;
int p, f, s, v, c;
int cp, cf, cs, cv, cc;

int min_price = INF;

vector<vector<int>> ret;

void init() {
  cin >> n;
  for (int i = 0; i < 4; i++) cin >> _max[i];
  for (int _ = 0; _ < n; _++) {
    cin >> p >> f >> s >> v >> c;
    foods.push_back({c, {p, f, s, v}});
  }
}

void go() {
  for (int i = 0; i < (1 << n); i++) {
    p = f = s = v = c = 0;
    vector<int> temp;
    for (int j = 0; j < n; j++) {
      auto it = foods[j];
      int cc = it.first;
      tie(cp, cf, cs, cv) = it.second;
      if (i & (1 << j)) {
        temp.push_back(j + 1);
        p += cp;
        f += cf;
        s += cs;
        v += cv;
        c += cc;
      }
    }
    if (p >= _max[0] && f >= _max[1] && s >= _max[2] && v >= _max[3]) {
      if (min_price > c) {
        ret.clear();
        ret.push_back(temp);
        min_price = c;
      } else if (min_price == c) {
        ret.push_back(temp);
      }
    }
  }

  if (min_price == INF)
    cout << "-1\n";
  else {
    sort(ret.begin(), ret.end());
    cout << min_price << "\n";
    for (auto it : ret[0]) {
      cout << it << " ";
    }
    cout << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}