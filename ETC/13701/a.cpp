#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
bitset<33554432> bits;

void go() {
  while (true) {
    cin >> n;

    if (cin.eof()) {
      break;
    }

    if (!bits[n]) {
      bits[n] = 1;
      cout << n << " ";
    }
  }
  cout << "\n";
}

int main() {
  fastIO;
  go();
  return 0;
}