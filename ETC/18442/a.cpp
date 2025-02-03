#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int v, p, l, n;
vector<int> vils;

void init() {
  cin >> v >> p >> l;
  for (int _ = 0; _ < v; _++) {
    cin >> n;
    vils.push_back(n);
  }
}

void go() {}

int main() {
  fastIO;
  init();
  go();
}