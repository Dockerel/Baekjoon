#include <bits/stdc++.h>
#define MAX 1504
using namespace std;

int r, c, y, x, ny, nx, ret = 0;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
string s;
pair<int, int> swan;
char a[MAX][MAX];
int waterV[MAX][MAX], swanV[MAX][MAX];
queue<pair<int, int>> swanQ, waterQ;
queue<pair<int, int>> sTempQ, wTempQ;

void swapQueue() {
  queue<pair<int, int>> t1, t2;
  swap(sTempQ, t1);
  swap(wTempQ, t2);
}

bool move_swan() {
  while (swanQ.size()) {
    tie(y, x) = swanQ.front();
    swanQ.pop();

    for (int i = 0; i < 4; i++) {
      ny = dy[i] + y;
      nx = dx[i] + x;

      if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
      if (swanV[ny][nx]) continue;

      if (a[ny][nx] == '.') {
        swanV[ny][nx] = 1;
        swanQ.push({ny, nx});
      } else if (a[ny][nx] == 'X') {
        swanV[ny][nx] = 1;
        sTempQ.push({ny, nx});
      } else if (a[ny][nx] == 'L') {
        return true;
      }
    }
  }
  return false;
}

void ice_melting() {
  while (waterQ.size()) {
    tie(y, x) = waterQ.front();
    waterQ.pop();

    for (int i = 0; i < 4; i++) {
      ny = dy[i] + y;
      nx = dx[i] + x;
      if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
      if (waterV[ny][nx]) continue;

      if (a[ny][nx] == 'X') {
        wTempQ.push({ny, nx});
        a[ny][nx] = '.';
        waterV[ny][nx] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < c; j++) {
      a[i][j] = s[j];
      if (s[j] == 'L') {
        swan = {i, j};
      }
      if (s[j] == 'L' || s[j] == '.') {
        waterV[i][j] = 1;
        waterQ.push({i, j});
      }
    }
  }

  swanQ.push(swan);
  swanV[swan.first][swan.second] = 1;

  while (1) {
    // move swan
    if (move_swan()) break;
    // ice melting
    ice_melting();

    swanQ = sTempQ;
    waterQ = wTempQ;
    swapQueue();
    ret++;
  }
  cout << ret << "\n";
  return 0;
}