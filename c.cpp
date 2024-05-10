#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void hanoi(int n, ll start, ll end) {
  if (n == 1) {
    cout << start << " " << end << "\n";
    return;
  }
  hanoi(n - 1, start, 6 - start - end);
  cout << start << " " << end << "\n";
  hanoi(n - 1, 6 - start - end, end);
}
int main() {
  int n;
  cin >> n;
  cout << (ll)pow(2, n) - 1 << "\n";
  hanoi(n, 1, 3);
  return 0;
}