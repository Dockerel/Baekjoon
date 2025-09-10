#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

int N, M, K;
ll a, b, c, num;
ll *tree;

void update(int node, int s, int e, int idx, ll data) {
  int m;
  if (s == e) {
    tree[node] = data;
    return;
  }
  m = (s + e) / 2;
  if (idx <= m)
    update(node * 2, s, m, idx, data);
  else
    update(node * 2 + 1, m + 1, e, idx, data);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int qs, int qe) {
  int m;
  if (e < qs || qe < s) return 0;
  if (qs <= s && e <= qe) return tree[node];
  m = (s + e) / 2;
  return query(node * 2, s, m, qs, qe) + query(node * 2 + 1, m + 1, e, qs, qe);
}

int main() {
  fastIO;

  cin >> N >> M >> K;
  tree = new ll[N * 4];
  for (int i = 1; i <= N; i++) {
    cin >> num;
    update(1, 1, N, i, num);
  }

  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      update(1, 1, N, b, c);
    } else {
      cout << query(1, 1, N, b, c) << "\n";
    }
  }

  return 0;
}