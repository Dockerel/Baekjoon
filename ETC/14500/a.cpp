#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

int n, m, ret;
int a[504][504];

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  ret = -INF;
}

void go() {
  // 1. 직선 테트로미노
  // 가로
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m - 4; j++) {
      ret = max(ret, a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3]);
    }
  }
  // 세로
  for (int i = 0; i <= n - 4; i++) {
    for (int j = 0; j < m; j++) {
      ret = max(ret, a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j]);
    }
  }
  // 2. 2x2 테트로미노
  for(int i=0;i<=n-2;i++){
    for(int j=0;j<=n-2;j++){
        ret=max(ret,a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]);
    }
  }
  // 3. 2x3 테트로미노
  for(int i=0;i<=n-3;i++){
    for(int j=0;j<=m-2;j++){
        // L
        ret=max(ret,a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1]); // 왼쪽아래
        ret=max(ret,a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]+a[i+2][j]); // 오른쪽아래
        ret=max(ret,a[i][j]+a[i][j+1]+a[i+1][j]+a[i+2][j]); // 왼쪽위
        ret=max(ret,a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]); // 오른쪽위

        // ㅗ
        ret=max(ret,a[i][j]+a[i+1][j]+a[i+2][j]+a[i+1][j+1]); // 3:1
        ret=max(ret,a[i+1][j]+a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]); // 1:3

        // N
        //o
        //oo
        // o
        ret=max(ret,a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1]);
        // o
        //oo
        //o
        ret=max(ret,a[i][j+1]+a[i+1][j+1]+a[i+1][j]+a[i+2][j]);
    }
  }

//   ret=max(ret,a[i][j]+a[i][j]+a[i][j]+a[i][j]);

  // 4. 3x2 테트로미노
  for(int i=0;i<=n-2;i++){
    for(int j=0;j<=m-3;j++){
        //L
        // 왼쪽아래
        ret=max(ret,a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
        // 오른쪽아래
        ret=max(ret,a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]+a[i][j+2]);
        // 왼쪽위
        ret=max(ret,a[i][j]+a[i+1][j]+a[i][j+1]+a[i][j+2]);
        // 오른쪽위
        ret=max(ret,a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2]);
        
        // ㅗ
        // up
        ret=max(ret,a[i][j+1]+a[i+1][j]+a[i+1][j+1]+a[i+1][j+2]);
        // down
        ret=max(ret,a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]);

        // z
        // oo
        //  oo
        ret=max(ret,a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2]);
        //  oo
        // oo
        ret=max(ret,a[i+1][j]+a[i+1][j+1]+a[i][j+1]+a[i][j+2]);
    }
  }
  cout<<ret<<"\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}