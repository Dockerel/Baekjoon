#include <bits/stdc++.h>
using namespace std;
int n, health, visited[64][64][64];

vector<int> h;

int d[6][3] = {
    {9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 3, 9}, {1, 9, 3},
};

struct A {
  int a, b, c;
};

void Input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> health;
    h.push_back(health);
  }
  for (int i = 0; i < 3 - n; i++) h.push_back(0);
}

void bfs() {
  queue<A> Q;
  Q.push({h[0], h[1], h[2]});
  while (!Q.empty()) {
    int a = Q.front().a;
    int b = Q.front().b;
    int c = Q.front().c;
    Q.pop();
    if (visited[0][0][0]) break;
    for (int i = 0; i < 6; i++) {
      int na = max(0, a - d[i][0]);
      int nb = max(0, b - d[i][1]);
      int nc = max(0, c - d[i][2]);
      if (visited[na][nb][nc]) continue;
      visited[na][nb][nc] = visited[a][b][c] + 1;
      Q.push({na, nb, nc});
    }
  }
}

void Solution() {
  bfs();
  return;
}

void Solve() {
  Input();
  Solution();
  cout << visited[0][0][0] << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
  return 0;
}