#include <bits/stdc++.h>
using namespace std;
int n;
int nb, ret;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  nb = 1;
  ret = 666;
  while (nb < n) {
    while (to_string(++ret).find("666") == string::npos)
      ;
    nb += 1;
  }
  cout << ret << "\n";
}