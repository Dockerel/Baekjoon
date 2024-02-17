#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, tmp, ret;
ll go(ll n) {
  if (n == 1) {
    return a % c;
  }
  tmp = go(n / 2);
  if (n % 2) return ((tmp * tmp) % c * (a % c)) % c;
  return (tmp * tmp) % c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c;
  ret = go(b);
  cout << ret;
  return 0;
}