#include <bits/stdc++.h>
using namespace std;
int n, health, ret, x, y, z, nx, ny, nz;
int dmg[3] = {9, 3, 1};
int dx[6] = {9, 9, 3, 3, 1, 1};
int dy[6] = {3, 1, 9, 1, 3, 9};
int dz[6] = {1, 3, 1, 9, 9, 1};
vector<int> h;

void Input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> health;
    h.push_back(health);
  }
  for (int i = 0; i <= 3 - n; i++) h.push_back(0);
}

void bfs() {
  queue<vector<int>> Q;
  Q.push(h);
  while (!Q.empty()) {
    vector<int> tmp = Q.front();
    Q.pop();

    x = tmp[0];
    y = tmp[1];
    z = tmp[2];
    ret = tmp[3];

    for (int i = 0; i < 6; i++) {
      nx = x - dx[i];
      ny = y - dy[i];
      nz = z - dz[i];
      if (nx <= 0 && ny <= 0 && nz <= 0) {
        cout << ret + 1 << "\n";
        exit(0);
      }
      tmp.clear();
      tmp.push_back(nx);
      tmp.push_back(ny);
      tmp.push_back(nz);
      tmp.push_back(ret + 1);
      Q.push(tmp);
    }
  }
  return;
}

void Solution() {
  bfs();
  return;
}

void Solve() {
  Input();
  Solution();
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  Solve();
  return 0;
}