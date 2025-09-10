#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long

using namespace std;

int n, num;
vector<int> v;
int temp;

/*
[백준] 5557번 : 1학년 (dp, Top-down)

d[i][j] => i번째 수까지 사용해서 j라는 수를 만들어낼 수 있는 경우의 수
e.g.) d[3][5] = 3번째 수까지 +,- 연산을 이용하여 5를 만들어 낼 수 있는 경우의 수

d[i][goal]는... >> i번째 수 까지 사용해서 goal 이라는 수를 만들어 낼 수 있는
경우의 수

a1  a2 ... + ai = goal    >> a1  a2   a(i-1) = goal-ai  >> d[i-1][goal-ai]
a1  a2     - ai = goal    >> a1  a2   a(i-1) = goal+ai  >> d[i-1][goal+ai]

이 2가지 경우의 합이다.
*/

ll dp[104][24];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    v.push_back(num);
  }
  memset(dp, 0, sizeof(dp));
  dp[0][v[0]] = 1;
}

void go() {
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 0; j <= 20; j++) {
      if (dp[i - 1][j]) {
        temp = j + v[i];
        if (temp >= 0 && temp <= 20) {
          dp[i][temp] += dp[i - 1][j];
        }
        temp = j - v[i];
        if (temp >= 0 && temp <= 20) {
          dp[i][temp] += dp[i - 1][j];
        }
      }
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  cout << dp[n - 2][v[n - 1]] << "\n";
  return 0;
}