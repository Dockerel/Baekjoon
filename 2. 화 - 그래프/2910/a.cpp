#include <bits/stdc++.h>
using namespace std;
int n, c, num = 0;
map<string, pair<int, int>> mp;  // 뭔지, 몇번나온지, 몇번째인지
string s;

bool cmp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
  if (a.second.first == b.second.first)
    return a.second.second < b.second.second;
  return a.second.first > b.second.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> s;

    auto it = mp.find(s);
    if (it == mp.end()) {
      mp[s] = {0, num++};
    }
    mp[s].first++;
  }

  vector<pair<string, pair<int, int>>> v(mp.begin(), mp.end());

  sort(v.begin(), v.end(), cmp);
  for (auto it : v) {
    for (int i = 0; i < it.second.first; i++) {
      cout << it.first << " ";
    }
  }
  cout << "\n";

  return 0;
}