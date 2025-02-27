#include <bits/stdc++.h>

int n, cnt1, cnt2, cnt3, heap[200001];

void f(int now) {
  if (now > n) return;

  cnt2++;
  heap[now] = -1;

  f(now * 2);
  f(now * 2 + 1);
}

int main() {
  int m, k, t;

  scanf("%d %d %d", &n, &m, &k);

  t = k / 2;
  while (t >= 1) {
    cnt1++;
    heap[t] = 1;
    t /= 2;
  }

  f(k * 2);
  f(k * 2 + 1);

  if (cnt1 >= m || cnt2 > n - m) {
    printf("-1");
    return 0;
  }

  cnt3 = cnt1 + 1;
  cnt1 = 1;
  cnt2 = n;
  for (int i = 1; i <= n; ++i) {
    if (i == k)
      printf("%d\n", m);
    else if (heap[i] == 1)
      printf("%d\n", cnt1++);
    else if (heap[i] == 0) {
      if (cnt3 == m) cnt3++;
      printf("%d\n", cnt3++);
    } else
      printf("%d\n", cnt2--);
  }

  return 0;
}