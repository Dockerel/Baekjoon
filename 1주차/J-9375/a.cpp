#include <bits/stdc++.h>
using namespace std;
int t, n, ret = 1;
map<string, int> mp;
string s1, s2;
char ch[30];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for (int i = 0; i < t; i++) {
    mp.clear();
    ret = 1;
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> s1 >> s2;
      auto tmp = mp.find(s2);
      if (tmp == mp.end())
        mp.insert({s2, 1});
      else
        tmp->second++;
    }
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
      ret *= ((iter->second) + 1);
    }
    cout << ret - 1 << "\n";
  }
  return 0;
}