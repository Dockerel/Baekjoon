#include <bits/stdc++.h>
using namespace std;
map<string, int> mp1;
map<int, string> mp2;
string s;
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    mp1.insert({s, i});
    mp2.insert({i, s});
  }
  for (int i = 0; i < m; i++) {
    cin >> s;
    if (isdigit(s.c_str()[0])) {
      cout << mp2.find(atoi(s.c_str()))->second;
    } else {
      cout << mp1.find(s)->second;
    }
    cout << "\n";
  }
  return 0;
}