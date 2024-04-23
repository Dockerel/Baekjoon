#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_pbds;

int n, num;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set X;

void init() {
  cin >> n;
  return;
}

void go() {
  for (int i = 0; i < n; i++) {
    cin >> num;
    X.insert({num, i});
    cout << X.find_by_order(i / 2)->first << "\n";
  }
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}