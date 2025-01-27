#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, _sum;
char a[5][5];
int slct[5][5];
int v[5][5];
string s, temp;
int ret;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];
    }
  }
  ret = -1;
}

void dfs(int y, int x, string curr) {
  if (slct[y][x] == 0) {  // 가로
    if (x + 1 >= m || slct[y][x + 1] == 1) {
      _sum += stoi(curr);
      return;
    }
    v[y][x + 1] = 1;
    dfs(y, x + 1, curr + a[y][x + 1]);
  } else {  // 세로
    if (y + 1 >= n || slct[y + 1][x] == 0) {
      _sum += stoi(curr);
      return;
    }
    v[y + 1][x] = 1;
    dfs(y + 1, x, curr + a[y + 1][x]);
  }
}

void go() {
  for (int k = 0; k < (1 << n * m); k++) {
    // k를 slct배열에 적용
    for (int i = 0; i < n; i++) {  // 0 ~ n*m-1
      for (int j = 0; j < m; j++) {
        slct[i][j] = (k & (1 << ((i * m) + j)) ? 1 : 0);
      }
    }

    // a배열과 slct배열로 합 구하기(dfs) : 0은 가로, 1은 세로
    _sum = 0;
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == 0) {
          v[i][j] = 1;
          temp = a[i][j];
          dfs(i, j, temp);
        }
      }
    }
    ret = max(ret, _sum);
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}