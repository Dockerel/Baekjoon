#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

using namespace std;

ll n, m, h, _max, _min, ret;
vector<ll> trees;

void init() {
  _max = -1;
  _min = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> h;
    trees.push_back(h);
    _max = max(_max, h);
  }
  sort(trees.begin(), trees.end(), greater<>());
}

void go() {
  while (_min <= _max) {
    ll _sum = 0;
    ll cut = (_min + _max) / 2;

    for (int i = 0; i < n; i++) {
      ll yield = trees[i] - cut;
      if (yield > 0)
        _sum += yield;
      else
        break;
    }

    if (_sum >= m) {
      ret = cut;
      _min = cut + 1;
    } else {
      _max = cut - 1;
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