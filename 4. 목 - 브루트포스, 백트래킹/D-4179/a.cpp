#include <bits/stdc++.h>
using namespace std;
int r, c, ret = 0, y, x, ny, nx;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
char maze[1004][1004];
string s;
queue<pair<int, int>> fireQ, jihunQ;
queue<pair<int, int>> fireTQ, jihunTQ;

void Input() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      maze[i][j] = s[j];
      if (s[j] == 'J')
        jihunQ.push({i, j});
      else if (s[j] == 'F')
        fireQ.push({i, j});
    }
  }
}

void Solution() {
  // 불 이동
  // 지훈 이동

  while (1) {
    while (!fireQ.empty()) {
      tie(y, x) = fireQ.front();
      fireQ.pop();
      for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;

        if (maze[ny][nx] == '.' || maze[ny][nx] == 'J') {
          maze[ny][nx] = 'F';
          fireTQ.push({ny, nx});
        }
      }
    }

    while (!jihunQ.empty()) {
      tie(y, x) = jihunQ.front();
      jihunQ.pop();
      for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
          cout << ret + 1 << "\n";
          exit(0);
        }

        if (maze[ny][nx] == '.') {
          maze[ny][nx] = 'J';
          jihunTQ.push({ny, nx});
        }
      }
    }

    if (jihunTQ.empty()) {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
    jihunQ = jihunTQ;
    fireQ = fireTQ;

    while (!jihunTQ.empty()) jihunTQ.pop();
    while (!fireTQ.empty()) fireTQ.pop();

    ret++;
  }
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