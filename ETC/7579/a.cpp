#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

// m만큼의 메모리 확보
// 메모리 사용량
// 비활성화 비용
// 필요한 메모리 m 바이트를 확보하기 위한 앱 비활성화의 최소의 비용을 계산하여
// 한 줄에 출력

int n, m, sumCost;
int memories[104];
int costs[104];
int dp[10004];  // i번째 앱까지 확인했을 때 j비용으로 얻을 수 있는 최대 메모리

int memory, cost;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> memories[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> costs[i];
    sumCost += costs[i];
  }
}

void go() {
  for (int i = 0; i < n; i++) {
    memory = memories[i];
    cost = costs[i];
    for (int j = sumCost; j >= cost; j--) {
      dp[j] = max(dp[j], dp[j - cost] + memory);
    }
  }

  for (int i = 0; i <= sumCost; i++) {
    if (dp[i] >= m) {
      cout << i << "\n";
      break;
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}