#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n1, n2, w;  // n1: 추, n2: 구슬

vector<int> v1, v2;  // v1: 추, v2: 구슬

// 구슬 하나를 선택해서 추들과의 조합을 통해 균형을 맞출 수 있는가(값이 같게
// 만들 수 있는가)
// -> 추들로만 만들 수 있는 무게의 조합을 dp로 구성해서 확인

int dp[34][40004];

void init() {
  cin >> n1;
  v1.push_back(0);
  for (int _ = 0; _ < n1; _++) {
    cin >> w;
    v1.push_back(w);
  }

  cin >> n2;
  for (int _ = 0; _ < n2; _++) {
    cin >> w;
    v2.push_back(w);
  }

  dp[0][0] = 1;
}

void go() {
  // 1. dp로 만들 수 있는 구슬 무게 조합 구하기
  // i번째 추까지 확인했을 때 j무게를 만들 수 있는지
  int wSum = accumulate(v1.begin(), v1.end(), 0);

  for (int i = 1; i < v1.size(); i++) {
    w = v1[i];
    for (int j = 0; j <= wSum; j++) {
      if (dp[i - 1][j]) {
        dp[i][j + w] = 1;
        dp[i][abs(j - w)] = 1;
        dp[i][j] = 1;
      }
    }
  }

  for (auto it : v2) {
    if (dp[v1.size() - 1][it])
      cout << "Y ";
    else
      cout << "N ";
  }
  cout << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}