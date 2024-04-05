#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<pair<int, int>, string>> v;

bool cmp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b) {
  if (a.first.second == b.first.second) return a.first.first < b.first.first;
  return a.first.second < b.first.second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    pair<pair<int, int>, string> temp;
    cin >> temp.first.second >> temp.second;
    temp.first.first = i;
    v.push_back(temp);
  }

  sort(v.begin(), v.end(), cmp);

  for (auto it : v) {
    cout << it.first.second << " " << it.second << "\n";
  }

  return 0;
}