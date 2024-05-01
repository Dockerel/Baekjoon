#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
int n, ret;
ll num;
vector<pair<ll, int>> a;
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    a.push_back({num, i});
  }
  sort(a.begin(), a.end());
  return;
}
void go() {
  for (int i = 0; i < n - 2; i++) {
    for (int j = i; j < n - 1; j++) {
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        if (a[i] + a[j] < a[k]) {
          break;
        } else if (a[i] + a[j] == a[k]) {
          ret++;
          break;
        }
      }
    }
  }
  cout << ret << "\n";
  return;
}
int main() {
  fastIO;
  init();
  go();
  return 0;
}