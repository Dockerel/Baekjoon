#include <bits/stdc++.h>
using namespace std;
int ret;
vector<pair<char, char>> v;
void hanoi(int n, char from, char to, char sub) {
  if (n == 1) {
    ret++;
    v.push_back({from, to});
    return;
  }
  hanoi(n - 1, from, sub, to);
  ret++;
  v.push_back({from, to});
  hanoi(n - 1, sub, to, from);
}
int main() {
  int n;
  cin >> n;
  hanoi(n, '1', '3', '2');
  cout << ret << "\n";
  for (auto it : v) {
    cout << it.first << " " << it.second << "\n";
  }
  return 0;
}