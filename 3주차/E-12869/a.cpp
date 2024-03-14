#include <bits/stdc++.h>
using namespace std;
int n, health, ret, x, y, z, nx, ny, nz;

int d1x = 9;

int d2x[2] = {9, 3};
int d2y[2] = {3, 9};

int d3x[6] = {9, 9, 3, 3, 1, 1};
int d3y[6] = {3, 1, 9, 1, 3, 9};
int d3z[6] = {1, 3, 1, 9, 9, 3};
vector<int> h;

void Input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> health;
    h.push_back(health);
  }
  h.push_back(0);
}

void bfs() {
  queue<vector<int>> Q;
  Q.push(h);
  while (!Q.empty()) {
    vector<int> tmp = Q.front();
    Q.pop();

    if (tmp.size() == 2) {
      x = tmp[0];
      ret = tmp[1];
      nx = x - d1x;
      if (nx <= 0) {
        cout << ret + 1 << "\n";
        exit(0);
      }
      tmp.clear();
      tmp.push_back(nx);
      tmp.push_back(ret + 1);
      Q.push(tmp);
    } else if (tmp.size() == 3) {
      x = tmp[0];
      y = tmp[1];
      ret = tmp[2];
      for (int i = 0; i < 2; i++) {
        nx = x - d2x[i];
        ny = y - d2y[i];
        if (nx <= 0 && ny <= 0) {
          cout << ret + 1 << "\n";
          exit(0);
        }
        tmp.clear();
        if (nx > 0) tmp.push_back(nx);
        if (ny > 0) tmp.push_back(ny);
        tmp.push_back(ret + 1);
        Q.push(tmp);
      }
    } else if (tmp.size() == 4) {
      x = tmp[0];
      y = tmp[1];
      z = tmp[2];
      ret = tmp[3];
      for (int i = 0; i < 6; i++) {
        nx = x - d3x[i];
        ny = y - d3y[i];
        nz = z - d3z[i];
        if (nx <= 0 && ny <= 0 && nz <= 0) {
          cout << ret + 1 << "\n";
          exit(0);
        }
        tmp.clear();
        if (nx > 0) tmp.push_back(nx);
        if (ny > 0) tmp.push_back(ny);
        if (nz > 0) tmp.push_back(nz);
        tmp.push_back(ret + 1);
        Q.push(tmp);
      }
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