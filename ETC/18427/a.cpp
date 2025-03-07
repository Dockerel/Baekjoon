#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, h;
char c;

// dp[i][j] : i번째 학생까지 확인했을 때 높이 j를 만들 수 있는 경우의 수
int dp[54][1004];

void init() {
  cin >> n >> m >> h;
  cin.get(c);
  dp[0][0] = 1;
}

void go() {
  vector<int> blocks;
  for (int i = 1; i <= n; i++) {
    // 입력
    string temp;
    // 블록 선택 안하는 경우
    blocks.push_back(0);
    while (1) {
      cin.get(c);
      if (c == '\n') break;
      if (c != ' ')
        temp.push_back(c);
      else {
        blocks.push_back(atoi(temp.c_str()));
        temp.clear();
      }
    }
    if (temp.size()) blocks.push_back(atoi(temp.c_str()));

    // 메인 로직
    for (int j = 0; j <= h; j++) {
      for (auto it : blocks) {
        if (j - it >= 0 && dp[i - 1][j - it])
          dp[i][j] += (dp[i - 1][j - it] % 10007);
      }
    }

    blocks.clear();
  }

  cout << dp[n][h] % 10007 << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}