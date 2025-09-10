#include <bits/stdc++.h>
using namespace std;
int n1;
string n2;
int main() {
  cin >> n1;
  cin >> n2;
  cout << n1 * (n2[2] - '0') << "\n";
  cout << n1 * (n2[1] - '0') << "\n";
  cout << n1 * (n2[0] - '0') << "\n";
  cout << n1 * ((n2[0] - '0') * 100 + (n2[1] - '0') * 10 + (n2[2] - '0'))
       << "\n";
  return 0;
}