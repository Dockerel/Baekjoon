#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pci pair<char, int>

using namespace std;

pci st[1000004];
int top = -1;
int s1len, s2len;
string s1, s2;

void push(pci a) { st[++top] = a; }
void pop() { top--; }
bool empty() {
  if (top == -1) return true;
  return false;
}

void init() {
  cin >> s1;
  cin >> s2;
  push({' ', -1});
  s1len = s1.length();
  s2len = s2.length();
}

void go() {
  for (int i = 0; i < s1len; i++) {
    auto it1 = st[top];
    if (it1.second == s2len - 1) top -= s2len;
    auto it2 = st[top];
    if (s1[i] == s2[it2.second + 1]) {
      push({s1[i], it2.second + 1});
    } else {
      if (s1[i] == s2[0]) {
        push({s1[i], 0});
      } else {
        push({s1[i], -1});
      }
    }
  }

  auto it3 = st[top];
  if (it3.second == s2len - 1)
    for (int _ = 0; _ < s2len; _++) {
      pop();
    }

  if (top + 1 > 1) {
    for (int i = 1; i <= top; i++) {
      cout << st[i].first;
    }
    cout << "\n";
  } else {
    cout << "FRULA\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}
