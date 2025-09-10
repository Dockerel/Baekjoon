#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, a, b;
int num;
string cmd;
int visited[10004];

queue<pair<int, string>> q;

void init() { cin >> t; }

int cmd_d(int n) { return (2 * n) % 10000; }

int cmd_s(int n) { return n == 0 ? 9999 : n - 1; }

int cmd_l(int n) { return ((n % 1000) * 10) + (n / 1000); }

int cmd_r(int n) { return (n / 10) + ((n % 10) * 1000); }

void go(int n1, int n2) {
  while (!q.empty()) q.pop();
  memset(visited, 0, sizeof(visited));

  q.push({n1, ""});
  visited[n1] = 1;
  while (true) {
    tie(num, cmd) = q.front();
    q.pop();
    if (num == n2) {
      cout << cmd << "\n";
      return;
    }
    int result_d = cmd_d(num);
    if (visited[result_d] == 0) {
      q.push({result_d, cmd + "D"});
      visited[result_d] = 1;
    }
    int result_s = cmd_s(num);
    if (visited[result_s] == 0) {
      q.push({result_s, cmd + "S"});
      visited[result_s] = 1;
    }
    int result_l = cmd_l(num);
    if (visited[result_l] == 0) {
      q.push({result_l, cmd + "L"});
      visited[result_l] = 1;
    }
    int result_r = cmd_r(num);
    if (visited[result_r] == 0) {
      q.push({result_r, cmd + "R"});
      visited[result_r] = 1;
    }
  }
}

int main() {
  fastIO;
  init();
  for (int _ = 0; _ < t; _++) {
    cin >> a >> b;
    go(a, b);
  }
  return 0;
}