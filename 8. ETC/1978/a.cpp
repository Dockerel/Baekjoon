#include <bits/stdc++.h>
using namespace std;
int n, num, ret = 0;
bool isPrime(int nb) {
  if (nb == 1) return false;
  for (int i = 2; i <= sqrt(nb); i++) {
    if (nb % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (isPrime(num)) ret++;
  }
  cout << ret << "\n";
}