#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;

int n, m, k;
ll a, b, c, num;
ll* arr;
ll* segtree;

void input() {
  cin >> n >> m >> k;
  arr = new ll[n + 1];
  segtree = new ll[n * 4];
  for (int i = 1; i <= n; i++) {
    cin >> num;
    arr[i] = num;
  }
}

ll segtree_init(int node, int start, int end) {
  if (start == end) {
    segtree[node] = arr[start];
    return segtree[node];
  }
  int mid = (start + end) / 2;
  segtree[node] = segtree_init(node * 2, start, mid) +
                  segtree_init(node * 2 + 1, mid + 1, end);
  return segtree[node];
}

void segtree_update(int node, int start, int end, int idx, ll data) {
  if (start == end) {
    segtree[node] = data;
    return;
  }
  int mid = (start + end) / 2;
  if (idx <= mid)
    segtree_update(node * 2, start, mid, idx, data);
  else
    segtree_update(node * 2 + 1, mid + 1, end, idx, data);
  segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
  return;
}

ll segtree_sum(int node, int start, int end, int left, int right) {
  if (end < left || right < start) return 0;
  if (left <= start && end <= right) return segtree[node];
  int mid = (start + end) / 2;
  return segtree_sum(node * 2, start, mid, left, right) +
         segtree_sum(node * 2 + 1, mid + 1, end, left, right);
}

void go() {
  segtree_init(1, 1, n);
  for (int i = 0; i < m + k; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      segtree_update(1, 1, n, b, c);
    } else {
      cout << segtree_sum(1, 1, n, b, c) << "\n";
    }
  }
}

int main() {
  fastIO;
  input();
  go();
  return 0;
}