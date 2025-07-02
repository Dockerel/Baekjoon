#include <stdio.h>

int icp[8] = {20, 19, 12, 12, 13, 13, 13, 0};
int isp[8] = {0, 19, 12, 12, 13, 13, 13, 0};

enum precedence { lparen, rparen, plus, minus, mult, div, mod, eos, num };

int top = -1;
char stack[104] = {0};

void push(char token) { stack[++top] = token; }

char pop() { return stack[top--]; }

int isEmpty() { return top == -1 ? 1 : 0; }

void init(char* str) { scanf("%s", str); }

int getToken(char* str, int* n, char* token) {
  *token = str[*n];
  switch (str[(*n)++]) {
    case '(':
      return lparen;
    case ')':
      return rparen;
    case '+':
      return plus;
    case '-':
      return minus;
    case '*':
      return mult;
    case '/':
      return div;
    case '%':
      return mod;
    case '\0':
      return eos;
    default:
      return num;
  }
}

int getPrecedence(char token) {
  switch (token) {
    case '(':
      return lparen;
    case ')':
      return rparen;
    case '+':
      return plus;
    case '-':
      return minus;
    case '*':
      return mult;
    case '/':
      return div;
    case '%':
      return mod;
    case '\0':
      return eos;
    default:
      return num;
  }
}

void go(char* str) {
  char token;
  int n = 0;
  enum precedence prec;

  while ((prec = getToken(str, &n, &token)) != eos) {
    if (prec == num) {
      printf("%c", token);
    } else if (prec == lparen) {
      push(token);
    } else if (prec == rparen) {
      while (stack[top] != '(') {
        printf("%c", pop());
      }
      pop();
    } else {
      while (!isEmpty() && icp[prec] <= isp[getPrecedence(stack[top])]) {
        printf("%c", pop());
      }
      push(token);
    }
  }

  while (!isEmpty()) {
    printf("%c", pop());
  }
  printf("\n");
}

int main() {
  char str[104];
  init(str);
  go(str);
}