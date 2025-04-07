#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int k, limit;
int tree[1028];

void inorder(int node) {
  if (node < limit) {
    inorder(node * 2);
    cin >> tree[node];
    inorder(node * 2 + 1);
  }
}

int isPowerOf2(int n) { return (n & (n - 1)) == 0; }

int main() {
  fastIO;

  cin >> k;
  limit = pow(2, k);

  inorder(1);

  for (int i = 1; i < limit; i++) {
    if (isPowerOf2(i) && i != 1) cout << "\n";
    cout << tree[i] << " ";
  }
  cout << "\n";

  return 0;
}