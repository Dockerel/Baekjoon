#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using namespace __gnu_pbds;

int t, n, num;
char cmd;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
ordered_set X;

void init() {
  cin >> n;
  while (X.size() > 0) X.erase(X.find_by_order(0));
}

void go() {
  for (int i = 0; i < n; i++) {
    cin >> cmd >> num;
    if (cmd == 'I') {
      X.insert({num, i});
    } else {
      if (X.size() > 0) {
        if (num == 1) {  // 최댓값 제거
          if (X.size() > 0) {
            X.erase(X.find_by_order(X.size() - 1));
          }
        } else {  // 최솟값 제거
          if (X.size() > 0) {
            X.erase(X.find_by_order(0));
          }
        }
      }
    }
  }
  if (X.size() > 0)
    cout << X.find_by_order(X.size() - 1)->first << " "
         << X.find_by_order(0)->first << "\n";
  else
    cout << "EMPTY\n";
}

int main() {
  fastIO;
  cin >> t;
  while (t--) {
    init();
    go();
  }
  return 0;
}