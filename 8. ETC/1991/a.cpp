#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
char tree[26][2];
char p, l, r;

void init() {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 2; j++) {
      tree[i][j] = '.';
    }
  }

  cin >> n;
  for (int _ = 0; _ < n; _++) {
    cin >> p >> l >> r;
    if (l != '.') tree[p - 'A'][0] = l;
    if (r != '.') tree[p - 'A'][1] = r;
  }
}

void preorder(char curr) {
  cout << curr;
  if (tree[curr - 'A'][0] != '.') preorder(tree[curr - 'A'][0]);
  if (tree[curr - 'A'][1] != '.') preorder(tree[curr - 'A'][1]);
}
void inorder(char curr) {
  if (tree[curr - 'A'][0] != '.') inorder(tree[curr - 'A'][0]);
  cout << curr;
  if (tree[curr - 'A'][1] != '.') inorder(tree[curr - 'A'][1]);
}
void postorder(char curr) {
  if (tree[curr - 'A'][0] != '.') postorder(tree[curr - 'A'][0]);
  if (tree[curr - 'A'][1] != '.') postorder(tree[curr - 'A'][1]);
  cout << curr;
}

void go() {
  preorder('A');
  cout << "\n";
  inorder('A');
  cout << "\n";
  postorder('A');
  cout << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}