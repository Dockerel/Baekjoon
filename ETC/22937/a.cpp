#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll unsigned long long

using namespace std;

int n;

void init() { cin >> n; }

void go() {
  for (int _ = 0; _ < n; _++) {
    int sgn = 1;
    string s1, s2;

    cin >> s1 >> s2;

    if (s1[0] == '-') {
      sgn *= -1;
      s1 = s1.substr(1, 11);
    }
    if (s2[0] == '-') {
      sgn *= -1;
      s2 = s2.substr(1, 11);
    }

    ll n1 = (ll)(s1[0] - '0') * 1000000000 + stoi(s1.substr(2, 9));
    ll n2 = (ll)(s2[0] - '0') * 1000000000 + stoi(s2.substr(2, 9));

    string ret = to_string(n1 * n2);
    while (ret.length() < 18) ret = "0" + ret;

    if (sgn == -1) cout << '-';
    if (ret.length() > 18)
      cout << ret.substr(0, ret.length() - 18) << '.'
           << ret.substr(ret.length() - 18, 18) << '\n';
    else
      cout << 0 << '.' << ret << '\n';
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}