#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s)             \
  if ((p = malloc(s)) == NULL) { \
    exit(EXIT_FAILURE);          \
  }

int n;
char **arr;

int minRet = 987654321;
int maxRet = -987654321;

int dy[2] = {1, 0};
int dx[2] = {0, 1};

char st[10];
int top = -1;

void push(char c) { st[++top] = c; }

void pop() { top -= 1; }

void init() {
  scanf("%d\n", &n);

  MALLOC(arr, sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    MALLOC(arr[i], sizeof(int) * n);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c, temp;
      scanf("%c", &c);
      arr[i][j] = c;
      scanf("%c", &temp);
    }
  }
}

int calculate() {
  int ret = st[0] - '0';
  for (int i = 1; i <= top; i += 2) {
    switch (st[i]) {
      case '+':
        ret += st[i + 1] - '0';
        break;
      case '-':
        ret -= st[i + 1] - '0';
        break;
      case '*':
        ret *= st[i + 1] - '0';
        break;
      default:
        break;
    }
  }
  return ret;
}

void go(int currY, int currX) {
  if (currY == n - 1 && currX == n - 1) {
    int ret = calculate();
    if (ret < minRet) {
      minRet = ret;
    }
    if (maxRet < ret) {
      maxRet = ret;
    }
    return;
  }

  for (int i = 0; i < 2; i++) {
    int ny = currY + dy[i];
    int nx = currX + dx[i];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

    push(arr[ny][nx]);
    go(ny, nx);
    pop();
  }
}

int main() {
  init();
  push(arr[0][0]);
  go(0, 0);
  printf("%d %d\n", maxRet, minRet);
}