#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int isp[8] = {0, 19, 12, 12, 13, 13, 0};
int icp[8] = {20, 19, 12, 12, 13, 13, 0};
typedef enum {
  lparen,
  rparen,
  _plus,
  _minus,
  times,
  divide,
  eos,
  operand
} precedence;
stack<int> st;

string s, ret;

int charToInt(char c) {
  switch (c) {
    case '(':
      return lparen;
      break;
    case ')':
      return rparen;
      break;
    case '+':
      return _plus;
      break;
    case '-':
      return _minus;
      break;
    case '*':
      return times;
      break;
    case '/':
      return divide;
      break;
    default:
      return operand;
      break;
  }
}

char intToChar(int n) {
  switch (n) {
    case lparen:
      return '(';
      break;
    case rparen:
      return ')';
      break;
    case _plus:
      return '+';
      break;
    case _minus:
      return '-';
      break;
    case times:
      return '*';
      break;
    case divide:
      return '/';
      break;
    default:
      return ' ';
      break;
  }
}

void init() {
  cin >> s;
  ret = "";
  st.push(eos);
  return;
}

void go() {
  for (int i = 0; i < s.length(); i++) {
    if (charToInt(s[i]) == operand) {
      ret += s[i];
    } else if (s[i] == ')') {
      while (1) {
        if (st.top() == lparen) {
          st.pop();
          break;
        }
        ret += intToChar(st.top());
        st.pop();
      }
    } else {
      while (isp[st.top()] >= icp[charToInt(s[i])]) {
        ret += intToChar(st.top());
        st.pop();
      }
      st.push(charToInt(s[i]));
    }
  }

  while (st.size() > 1) {
    ret += intToChar(st.top());
    st.pop();
  }

  cout << ret << "\n";
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}