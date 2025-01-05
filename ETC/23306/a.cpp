#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, start, _end;

void init() { cin >> n; }

void go() {
  cout << "? 1" << endl;
  cin >> start;

  cout << "? " << n << endl;
  cin >> _end;

  if (start == _end) {
    cout << "! 0" << endl;
  } else {
    cout << (start > _end ? "! -1" : "! 1") << endl;
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}