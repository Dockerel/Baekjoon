#include <stdio.h>

int st[1000004];
int top = -1;

int n, cmd, num;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &cmd);
    switch (cmd) {
      case 1:
        scanf("%d", &num);
        st[++top] = num;
        break;
      case 2:
        printf("%d\n", top >= 0 ? st[top--] : -1);
        break;
      case 3:
        printf("%d\n", top + 1);
        break;
      case 4:
        printf("%d\n", top == -1 ? 1 : 0);
        break;
      case 5:
        printf("%d\n", top >= 0 ? st[top] : -1);
        break;
      default:
        break;
    }
  }
}