// if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
//     1

// if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
//     w(20, 20, 20)

// if a < b and b < c, then w(a, b, c) returns:
//     w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

// otherwise it returns:
//     w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int a, b, c;
int dp[24][24][24];

void init() { memset(dp, 0, sizeof(dp)); }

bool inRange(int a, int b, int c) {
  if (a >= 0 && b >= 0 && c >= 0 && a <= 20 && b <= 20 && c <= 20) return true;
  return false;
}

int w(int a, int b, int c) {
  if (inRange(a, b, c) && dp[a][b][c]) return dp[a][b][c];

  if (a <= 0 || b <= 0 || c <= 0) {
    if (inRange(a, b, c)) {
      dp[a][b][c] = 1;
      return dp[a][b][c];
    } else
      return 1;
  } else if (a > 20 || b > 20 || c > 20) {
    if (inRange(a, b, c)) {
      dp[a][b][c] = w(20, 20, 20);
      return dp[a][b][c];
    } else
      return w(20, 20, 20);
  }
  if (a < b && b < c) {
    if (inRange(a, b, c)) {
      dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
      return dp[a][b][c];
    } else
      return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  } else {
    if (inRange(a, b, c)) {
      dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
                    w(a - 1, b - 1, c - 1);
      return dp[a][b][c];
    } else
      return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
             w(a - 1, b - 1, c - 1);
  }
}

void go() {
  while (1) {
    cin >> a >> b >> c;
    if (a == -1 && b == -1 && c == -1) {
      break;
    }
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}