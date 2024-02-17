#include <bits/stdc++.h>
using namespace std;
void zero(int n) {
  int count = 0;
  for (int i = 5; i <= n; i *= 5) {
    count += n / i;
  }
  cout << count << "\n";
}
int main() {
  int n, nb;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nb;
    zero(nb);
  }

  return 0;
}