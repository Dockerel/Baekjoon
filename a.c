#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int data;
} node;

node a[3];

int cmp(const void* a, const void* b) {
  return ((node*)a)->data - ((node*)b)->data;
}

void _print() {
  for (int i = 0; i < 3; i++) {
    printf("%d ", a[i].data);
  }
  printf("\n");
}

int main(void) {
  for (int i = 0; i < 3; i++) {
    node temp;
    temp.data = 3 - i;
    a[i] = temp;
  }

  _print();

  qsort(a, 3, sizeof(node), cmp);

  _print();

  return 0;
}